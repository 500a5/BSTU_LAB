import math
from scipy.integrate import *
import numpy as np


# Система дифф. уравнений x1, x2.
def diff_funcs(t, y, p1, p2):
	return [
		np.cos(p1) - p2,
		p1 + t
	]


# Измеряемая функция s.
def s_func(x1: float, x2: float) -> float:
	return x1 * x2*2


# Возвращает вектор s, полученный путем решения системы дифф. уравнений и
# вычислением измеряемой функции s.
def integrate(args: list):
	global t_i, x0

	ivp = solve_ivp(diff_funcs, (0, t_i[-1]), x0, t_eval=t_i, args=args, max_step=0.1)
	return [s_func(ivp.y[0][i], ivp.y[1][i]) for i in range(len(t_i))]


# Возвращает обратную к матрице matrix 2 порядка.
def inv(matrix):
	det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]

	a11, a12, a21, a22 = matrix[1][1], -matrix[1][0], -matrix[0][1], matrix[0][0]

	return np.array([[a11/det, a12/det], [a21/det, a22/det]])


if __name__ == '__main__':
	# +------------------+
	# | Исходные данные. |
	# +------------------+

	# Вектор измерений.
	r = [
		-27.9220160870,
		359.3016348300,
		-459.4081624400,
		-514.1890451900,
		-36.5725516200,
		663.8740197600,
		705.7564359000,
		-1075.2696504000,
		-1138.15617000,
		70.93166
	]

	# Диаг. эл-ты корр матрицы.
	k_v_el = [
		0.0000077943,
		0.0012914645,
		0.0021105077,
		0.0023437548,
		0.0000133736,
		0.0044070193,
		0.0049804057,
		0.0115632756,
		0.0129540557,
		0.0000502719
	]

	# Количество шагов измерений.
	n = 10
	# Шаги измерений.
	t_i = [50, 100, 140, 200, 250, 300, 350, 400, 450, 500]

	# Эпсилон.
	eps = 1.0E-1

	# Вектор начальных условий.
	x0 = [7, 15]

	# 1. Задаем начальные значения вектора оцениваемых параметров.
	o = [1, 4]

	# 3.a. Вычисляем обратную матрицу Kv^(-1).
	k_v = np.zeros((n, n))
	for i in range(n):
		k_v[i][i] = 1 / k_v_el[i]

	dp = 0.1

	s = None
	dr = None
	do = [1, 1]

	while abs(do[0]) > eps and abs(do[1]) > eps:
		# 2. Интегрируем систему дифф уравнений и в заданные моменты t_i запоминаем значения функции s.
		s = integrate(o)

		# 3.b. Вычисляем матрицу M.
		s1_plus = integrate([o[0] + dp, o[1]])
		s1_minus = integrate([o[0] - dp, o[1]])

		s2_plus = integrate([o[0], o[1] + dp])
		s2_minus = integrate([o[0], o[1] - dp])

		m = [
			[(s1_plus[i] - s1_minus[i])/(2*dp) for i in range(len(t_i))],
			[(s2_plus[i] - s2_minus[i])/(2*dp) for i in range(len(t_i))]
		]

		# 3.c. Вычисляем вектор dR.
		dr = [[r[i] - s[i] for i in range(len(r))]]
		dr = np.array(dr)
		dr_t = dr.T

		# 3.d. Транспонируем матрицу M.
		m = np.array(m)
		m_t = m.T

		# 3.e. Вычисляем dO.
		tmp = np.dot(np.dot(m, k_v), m_t)

		do = np.dot(np.dot(np.dot(inv(tmp), m), k_v), dr_t)

		o[0] += do[0][0]
		o[1] += do[1][0]

	print('p1 = {0}, p2 = {1}\n'.format(o[0], o[1]))
