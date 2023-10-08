#include "simpleobject.h"

SimpleObject::SimpleObject(){
}

SimpleObject::SimpleObject(const QString &name, QVector4D color):
    arrayBuffer(), indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0)
{
    init(name, color);
}

SimpleObject::~SimpleObject(){
    if (arrayBuffer.isCreated()) arrayBuffer.destroy();
    if (indexBuffer.isCreated()) indexBuffer.destroy();
}

QVector3D findMinXY(const QVector<VertexData> &vd){
    QVector3D min = vd[0].position;
    for (int i = 0; i < vd.size(); i++)
        if (vd[i].position.x() <= min.x() && vd[i].position.y() <= min.y())
            min = vd[i].position;
    return min;
}
QVector3D findMaxXY(const QVector<VertexData> &vd){
    QVector3D max = vd[0].position;
    for (int i = 0; i < vd.size(); i++)
        if (vd[i].position.x() >= max.x() && vd[i].position.y() >= max.y())
            max = vd[i].position;
    return max;
}
QVector3D findCenter(const QVector<VertexData> &vd){
    float x = 0, y = 0, z = 0;
    for (int i = 0; i < vd.size(); i++){
        x += vd[i].position.x();
        y += vd[i].position.y();
        z += vd[i].position.z();
    }
    return QVector3D(x/vd.size(), y/vd.size(), z/vd.size());
}

void SimpleObject::init(const QString &name, QVector4D color){
    this->color = color;
    if (arrayBuffer.isCreated()) arrayBuffer.destroy();
    if (indexBuffer.isCreated()) indexBuffer.destroy();

    QVector<VertexData> vertData;
    QVector<uint> indexes;
    load_obj(name, vertData, indexes);

    min = findMinXY(vertData);
    max = findMaxXY(vertData);
    center = findCenter(vertData);

    arrayBuffer.create();
    arrayBuffer.bind();
    arrayBuffer.allocate(vertData.constData(), vertData.size()*sizeof(VertexData));
    arrayBuffer.release();

    indexBuffer.create();
    indexBuffer.bind();
    indexBuffer.allocate(indexes.constData(), indexes.size()*sizeof(uint));
    indexBuffer.release();

    modelMatrix.setToIdentity();
    k = 1; trans = QVector3D(0,0,0);
    r_x = r_y = r_z = 0;
}

void SimpleObject::drawObject(QOpenGLShaderProgram *sh_program, QOpenGLFunctions *functions){
    if (!arrayBuffer.isCreated() || !indexBuffer.isCreated()) return;


    sh_program->setUniformValue("u_modelMatrix", modelMatrix);
    sh_program->setUniformValue("u_objColor", color);
    sh_program->setUniformValue("u_use_texture", use_texture);

    int offset = 0;
    arrayBuffer.bind();
    int vertLoc = sh_program->attributeLocation("a_position");
    sh_program->enableAttributeArray(vertLoc);
    sh_program->setAttributeBuffer(vertLoc, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);    // смещение для текстурных координат
    //текстурные координаты
    if (use_texture){
        texture->bind(0);
        sh_program->setUniformValue("u_texture", 0);
        int texLoc = sh_program->attributeLocation("a_texCoord");
        sh_program->enableAttributeArray(texLoc);
        sh_program->setAttributeBuffer(texLoc, GL_FLOAT, offset, 2, sizeof(VertexData));
    }

    offset += sizeof(QVector2D);
    int normalLoc = sh_program->attributeLocation("a_normal");
    sh_program->enableAttributeArray(normalLoc);
    sh_program->setAttributeBuffer(normalLoc, GL_FLOAT, offset, 3, sizeof(VertexData));

    indexBuffer.bind();
    functions->glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);

    arrayBuffer.release();
    indexBuffer.release();
}

void SimpleObject::scale(float k){
    if (abs(k) < 0.0001f) return;
    this->k *= k;
    updateModelMatrix();
}

void SimpleObject::translate(const QVector3D &vec){
    trans += vec;
    updateModelMatrix();
}

void SimpleObject::rotateX(float angle){
    r_x += angle;
    updateModelMatrix();
}

void SimpleObject::rotateY(float angle){
    r_y += angle;
    updateModelMatrix();
}

void SimpleObject::rotateZ(float angle){
    r_z += angle;
    updateModelMatrix();
}

void SimpleObject::updateModelMatrix(){
    modelMatrix.setToIdentity();
    modelMatrix.rotate(r_x, 1, 0, 0);
    modelMatrix.rotate(r_y, 0, 1, 0);
    modelMatrix.rotate(r_z, 0, 0, 1);
    modelMatrix.translate(trans);
    modelMatrix.scale(k, k, k);
}

void SimpleObject::setTexture(QString name){
    texture = new QOpenGLTexture(QImage(name)); // mirrored;
    use_texture = true;
}


//-------------------------------------------------------------------------------

ChessFigure::ChessFigure(const QString &name, int grid_sz, int field_sz, int x, int y, int team):
    SimpleObject(name), grid_sz(grid_sz), field_sz(field_sz), team(team)
{
    enable = false;
    if (team == TEAM_WHITE) defaultColor = QVector4D(1.0, 1.0, 1.0, 1.0);
        else defaultColor = QVector4D(0.2, 0.2, 0.2, 1.0);
    color = defaultColor;
    enableColor = QVector4D(0.45, 0.8, 0.55, 1.0);
    pos_x = x;
    pos_y = y;
    float x1 = grid_sz*(x-field_sz/2) - grid_sz/2.f;
    float y1 = grid_sz*(y-field_sz/2) - grid_sz/2.f;
    modelMatrix.translate(x1, y1, 0.0);
}

void ChessFigure::move(int x1, int y1){
    float dx = (x1 - pos_x) * grid_sz;
    float dy = (y1 - pos_y) * grid_sz;
    modelMatrix.translate(dx, dy, 0.0);
    pos_x = x1;
    pos_y = y1;
}

bool ChessFigure::onThisPos(int x, int y){
    return pos_x == x && pos_y == y;
}

void ChessFigure::select(){
    enable = true;
    color = enableColor;
}

void ChessFigure::deselect(){
    enable = false;
    color = defaultColor;
}

int ChessFigure::getTeam(){
    return team;
}

//---------------------------------------------------------------------------------------

LampObject::LampObject(const QString &name, QVector4D base_color, QVector4D light_color):
    SimpleObject(name, base_color), turn_on(false), base_color(base_color), light_color(light_color),
    power(1.0f), constant(1.0f), linear(0.004f), quadratic(0.00007f){
}

void LampObject::setState(bool state){
    turn_on = state;
    if (turn_on)
        color = light_color;
    else
        color = base_color;
}

PointLightStruct LampObject::getPointLightStruct(){
    PointLightStruct strct;
    strct.pos = getCenterOfMass();
    strct.power = power;
    strct.color = color;
    strct.linear = linear;
    strct.constant = constant;
    strct.quadratic = quadratic;
    return strct;
}

void LampObject::drawObject(QOpenGLShaderProgram *sh_program, QOpenGLFunctions *functions){
    if (turn_on){
        qDebug() << "Лампа включена, но вызвано отрисовывание выключеной лампы";
        return;
    }
    SimpleObject::drawObject(sh_program, functions);
}

void LampObject::drawObjAsLamp(QOpenGLShaderProgram *sh_program, QOpenGLFunctions *functions){
    if (!turn_on){
        qDebug() << "Лампа выключена, но вызвано отрисовывание включеной лампы";
        return;
    }
    SimpleObject::drawObject(sh_program, functions);
}

//-------------------------------------------------------------------------------------------

SpotLightStruct Spot::getSpotLightStruct(){
    SpotLightStruct strct;
    strct.pos = position;
    strct.color = light_color;
    strct.power = power;
    strct.direction = direction;
    strct.cutOff = cutOff;
    return strct;
}

void Spot::setPositionAndDirection(QVector3D pos, QVector3D dir_point){
    position = pos;
    direction = QVector3D(pos - dir_point).normalized();
}
