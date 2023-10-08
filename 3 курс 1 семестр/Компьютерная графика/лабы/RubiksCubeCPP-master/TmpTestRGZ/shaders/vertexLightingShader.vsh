#version 130

// Вершина
in vec4 vertex;

// Вектор нормали к вершине
in vec3 normal;

// Результирующая матрица
uniform mat4 matrix;

// Матрица для умножения векторов нормалей
uniform mat3 normalMatrix;

// Видовая матрица для нахождения мировых координат вершин при расчёте освещения
uniform mat4 modelViewMatrix;

// Вектор нормали и позиция фрагмента, которые будут переданы по конвейеру далее
out vec3 fragNormal;
out vec3 fragPos;

void main(void)
{
   gl_Position = matrix * vertex;

   // Для расчёта освещения необходимо знать координаты вершин в пространстве видовых преобразований,
   // поэтому нужно умножать только видовую матрицу (не выполнять проектирование) на исходные координаты вершин
   fragPos = vec4(modelViewMatrix * vertex).xyz;

   // Рассчитаем вектор нормали для фрагментного шейдера
   fragNormal = normalMatrix * normal;
}
