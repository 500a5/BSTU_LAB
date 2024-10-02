#include "import_obj.h"

//загружает .obj модель файла
void load_obj(const QString &f_name, QVector<VertexData> &v_data, QVector<uint> &indexes){
    v_data.clear();
    QFile obj_f(f_name);
    if (!obj_f.exists()){
        qDebug() << "Файл " << f_name << " не найден!";
        return;
    }
    obj_f.open(QIODevice::ReadOnly);
    QTextStream input(&obj_f);
    QString str;
    QStringList list, list_f;
    QVector<QVector3D> vert;
    QVector<QVector2D> tex_coord;
    QVector<QVector3D> normals;
    while(!input.atEnd()){
        str = input.readLine();
        list = str.split(" ");
        if (list[0] == "v"){
            vert.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        if (list[0] == "vt"){
            tex_coord.append(QVector2D(list[1].toFloat(), list[2].toFloat()));
            continue;
        }
        if (list[0] == "vn"){
            normals.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        if (list[0] == "f"){
            for (int i = 1; i <= 3; i++){
                list_f = list[i].split("/");
                if (list_f[1].size() == 0 && list_f[2].size() == 0)
                    v_data.append(VertexData(vert[list_f[0].toLong()-1]));

                if (list_f[1].size() == 0 && list_f[2].size() != 0)
                    v_data.append(VertexData(vert[list_f[0].toLong()-1], normals[list_f[2].toLong()-1]));

                if (list_f[1].size() != 0 && list_f[2].size() == 0)
                    v_data.append(VertexData(vert[list_f[0].toLong()-1], tex_coord[list_f[1].toLong()-1]));

                if (list_f[1].size() != 0 && list_f[2].size() != 0)
                    v_data.append(VertexData(vert[list_f[0].toLong()-1], tex_coord[list_f[1].toLong()-1], normals[list_f[2].toLong()-1]));

                indexes.append((uint)indexes.size());
            }
        }
    }
    obj_f.close();
}
