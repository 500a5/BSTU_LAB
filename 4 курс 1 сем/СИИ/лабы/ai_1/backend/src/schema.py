from typing import List
from pydantic import BaseModel


class Request(BaseModel):
    init_t: float
    final_t: float
    alpha: float
    step: int
    count: int


class Point(BaseModel):
    x: float
    y: float


class GraphicSchema(BaseModel):
    name: str
    data: List[Point]


class Response(BaseModel):
    solution: List[int]
    graphics: List[GraphicSchema] = []
