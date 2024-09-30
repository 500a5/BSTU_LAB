import random
from fastapi.routing import APIRouter
from schema import Request, Response
from src.annealing import SimulatedAnnealing


router = APIRouter()


@router.post("", response_model=Response)
def get_solution(
        request: Request
):
    random.seed()
    simulation = SimulatedAnnealing(
        request.init_t,
        request.final_t,
        request.alpha,
        request.step,
        request.count
    )

    solution = simulation.get_solution()

    return {
        "solution": solution.solution,
        "graphics": [
            {
                "name": 'Температура',
                "data": simulation.temperature_statistic,
            },
            {
                "name": 'Принятия плохих решений',
                "data": simulation.worst_statistic,
            },
            {
                "name": 'Энергия лучшего решения',
                "data": simulation.best_statistic,
            }
        ]
    }
