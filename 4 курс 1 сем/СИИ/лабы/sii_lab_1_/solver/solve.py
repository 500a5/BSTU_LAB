import random
from .annealing import SimulatedAnnealing


def solve(
    init_t: int,
    final_t: int,
    alpha: float,
    step_per_change: float,
    count_figures: int
):
    random.seed()
    simulation = SimulatedAnnealing(
        init_t,
        final_t,
        alpha,
        step_per_change,
        count_figures
    )

    solution = simulation.get_solution()
    graphics = [
        {
            "name": 'Температура',
            "data": simulation.t_stats,
        },
        {
            "name": 'Принятия плохих решений',
            "data": simulation.bed_statistic,
        },
        {
            "name": 'Энергия лучшего решения',
            "data": simulation.best_stats,
        }
    ]

    return solution.solution, graphics
