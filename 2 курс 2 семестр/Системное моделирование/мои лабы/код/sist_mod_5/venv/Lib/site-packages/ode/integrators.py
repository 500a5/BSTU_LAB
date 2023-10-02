# -*- coding: utf-8 -*-
# integrators

__all__ = [
        'Euler', 'euler',
        'Verlet', 'verlet',
        'BackwardEuler', 'backwardeuler',
          ]


import numpy as np


class Integrator:
    def __init__(self, dfun, xzero, timerange):
        '''Initializes dfun, xzero, timestart, timeend,
        sets time at start and steps to zero.'''
        assert len(timerange) == 2
        self.timestart, self.timeend = timerange
        self.time = self.timestart
        # check output of dfun, wrap w/ np.array if necessary
        xtest = dfun(self.time, xzero)
        if not isinstance(xtest, np.ndarray):
            xtest = np.array(xtest)
            def array_dfun(t, x):
                x = dfun(t, x)
                xarray = np.array(x)
                return xarray
            self.dfun = array_dfun
        else:
            self.dfun = dfun
        if len(xtest.shape) != 1:
            raise Exception(f'dfun: {dfun} output is not one dimensional')
        if not isinstance(xzero, np.ndarray):
            xzero = np.array(xzero)
        assert len(xzero.shape) == 1, 'xzero must be one dimensional'
        self.x = xzero
        self.stepcounter = 0

    def __iter__(self):
        return self


class ConstantTimestep(Integrator):
    '''The __init__ function of this class sets instance variables for
    integrators with a constant timestep.'''
    def __init__(self, dfun, xzero, timerange, timestep):
        super().__init__(dfun, xzero, timerange)
        assert ((self.timeend - self.timestart) / timestep) > 0, (
            "'timerange' and 'timestep' not consistant. "
            "Check signs and order.")
        self.timestep = timestep
        self.direction = np.sign(timestep)
        self.steps = np.ceil((self.timeend - self.timestart) / timestep)
        self.status = 'initialized'


class Euler(ConstantTimestep):
    '''Euler method integration. This class implements a generator.

        :param dfun:
            derivative function of the system.
            The differential system arranged as a series of first-order
            equations: :math:`\dot{X} = \mathrm{dfun}(t, x)`.
            Returns :math:`\dot{X}` should be a single dimensional array
            or list.
        :param xzero:
            the initial condition of the system
        :param timerange:
            the start and end times as (starttime, endtime) tuple/list/array.
        :param timestep:
            the timestep
        :returns: t, x for each iteration. t is a number. x is an array.
    '''

    def __next__(self):
        if self.stepcounter < self.steps:
            if self.status == 'initialized':
                self.status = 'running'
                return self.time, self.x
            else:
                self.stepcounter += 1
                dx = self.dfun(self.time, self.x)
                self.time, self.x = (
                    self.timestart + (self.stepcounter * self.timestep),
                    self.x + (self.timestep * dx))
                return self.time, self.x
        else:
            self.status = 'finished'
            raise StopIteration


def euler(dfun, xzero, timerange, timestep):
    '''Euler method integration. This function wraps the Euler class.

        :param All: All parameters are identical to the Euler class above.
        :returns: t, x as arrays.
    '''
    t_column, X = zip(*list(Euler(dfun, xzero, timerange, timestep)))
    t_column = np.array(t_column)
    X_columns = np.vstack(X).T
    return t_column, X_columns


class Verlet(ConstantTimestep):
    '''Verlet method integration. This class implements a generator.

        :param ddfun:
            second derivative function of the system.
            The differential system arranged as a series of second-order
            equations: :math:`\ddot{X} = \mathrm{dfun}(t, x)`
        :param xzero:
            the initial condition of the system
        :param vzero:
            the initial condition of first derivative of the system
        :param timerange:
            the start and end times as (starttime, endtime)
        :param timestep:
            the timestep
        :returns: t, x, v for each iteration.
    '''
    def __init__(self, ddfun, xzero, vzero, timerange, timestep):
        if not isinstance(vzero, np.ndarray):
            vzero = np.array(vzero)
        assert len(vzero.shape) == 1, 'vzero must be one dimensional'
        self.v = vzero
        if not isinstance(xzero, np.ndarray):
            xzero = np.array(xzero)
        assert len(xzero.shape) == 1, 'xzero must be one dimensional'
        self.xold = xzero
        super().__init__(ddfun, xzero, timerange, timestep)

    def __next__(self):
        if self.stepcounter < self.steps:
            if self.status == 'initialized':
                ddx = self.dfun(self.time, self.x)
                self.xnext = (
                        self.x
                        + (self.v * self.timestep)
                        + (ddx * (self.timestep**2) / 2))
                self.status = 'running'
                return self.time, self.x, self.v
            else:
                self.stepcounter += 1
                ddx = self.dfun(self.time + self.timestep, self.xnext)
                self.time, self.xold, self.x, self.xnext = [
                    self.timestart + (self.stepcounter * self.timestep),
                    self.x,
                    self.xnext,
                    (2 * self.xnext) - self.x + (ddx * (self.timestep**2))]
                self.v = (self.xnext - self.xold) / (2 * self.timestep)
                return self.time, self.x, self.v
        else:
            self.status = 'finished'
            raise StopIteration


def verlet(ddfun, xzero, vzero, timerange, timestep):
    '''Verlet method integration. This function wraps the Verlet class.

        :param All: All parameters are identical to the Verlet class above.
        :returns: t, x, v as arrays.
    '''
    t_column, X, V = zip(*list(Verlet(ddfun, xzero, vzero, timerange, timestep)))
    t_column = np.array(t_column)
    X_columns = np.vstack(X).T
    V_columns = np.vstack(V).T
    return t_column, X_columns, V_columns


class BackwardEuler(ConstantTimestep):
    '''Backward Euler method integration. This class implements a generator.

        :param dfun:
            Derivative function of the system.
            The differential system arranged as a series of first-order
            equations: :math:`\dot{X} = \mathrm{dfun}(t, x)`
        :param xzero:
            The initial condition of the system.
        :param vzero:
            The initial condition of first derivative of the system.
        :param timerange:
            The start and end times as (starttime, endtime).
        :param timestep:
           The timestep.
        :param convergencethreshold:
            Each step requires an iterative solution of an implicit equation.
            This is the threshold of convergence.
        :param maxiterations:
            Maximum iterations of the implicit equation before raising
            an exception.
        :returns: t, x for each iteration.
    '''
    def __init__(self, dfun, xzero, timerange, timestep,
                 convergencethreshold=0.0000000001, maxiterations=1000):
        assert convergencethreshold > 0, 'convergencethreshold must be > 0'
        self.convergencethreshold = convergencethreshold
        assert maxiterations > 0, 'maxiterations must be > 0'
        self.maxiterations = maxiterations
        super().__init__(dfun, xzero, timerange, timestep)

    def __next__(self):
        if self.stepcounter < self.steps:
            if self.status == 'initialized':
                self.status = 'running'
                return self.time, self.x
            else:
                self.stepcounter += 1
                iterations = 0
                error = 1 + self.convergencethreshold
                xn1 = self.x
                while (
                        (error >= self.convergencethreshold) and
                        (iterations < self.maxiterations)):
                    iterations += 1
                    xn2 = self.x + (self.dfun(self.time, xn1) * self.timestep)
                    error = sum(abs(xn1 - xn2))
                    xn1 = xn2
                if error <= self.convergencethreshold:
                    self.time, self.x = (
                        self.timestart + (self.stepcounter * self.timestep),
                        xn1)
                    return self.time, self.x
                else:
                    raise RuntimeError('maximum iterations exceeded')
        else:
            self.status = 'finished'
            raise StopIteration


def backwardeuler(dfun, xzero, timerange, timestep):
    '''Backward Euler method integration. This function wraps BackwardEuler.

        :param All: All parameters are identical to the BackwardEuler
            class above.
        :returns: t, x as arrays.
    '''
    t_column, X = zip(*list(BackwardEuler(dfun, xzero, timerange, timestep)))
    t_column = np.array(t_column)
    X_columns = np.vstack(X).T
    return t_column, X_columns

