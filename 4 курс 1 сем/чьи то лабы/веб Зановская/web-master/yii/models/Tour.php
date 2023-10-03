<?php

namespace app\models;

use Yii;

/**
 * This is the model class for table "tours".
 *
 * @property int $id
 * @property int $categoryId категория
 * @property string $title заголовок
 * @property string $text содержание
 * @property string $createdAt Дата создания
 * @property string|null $updatedAt Дата обновления
 * @property string $image картинка
 *
 * @property Description[] $descriptions
 * @property Categories $category
 * @property Categories $category0
 */
class Tour extends BaseModel
{
    /**
     * {@inheritdoc}
     */
    public static function tableName()
    {
        return 'tours';
    }

    /**
     * {@inheritdoc}
     */
    public function rules()
    {
        return [
            [['categoryId', 'title', 'text', 'createdAt', 'image'], 'required'],
            [['categoryId'], 'integer'],
            [['text'], 'string'],
            [['createdAt', 'updatedAt'], 'safe'],
            [['title', 'image'], 'string', 'max' => 128],
            [['categoryId'], 'exist', 'skipOnError' => true, 'targetClass' => Categories::className(), 'targetAttribute' => ['categoryId' => 'id']],
            [['categoryId'], 'exist', 'skipOnError' => true, 'targetClass' => Categories::className(), 'targetAttribute' => ['categoryId' => 'id']],
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'categoryId' => 'категория',
            'title' => 'заголовок',
            'text' => 'содержание',
            'createdAt' => 'Дата создания',
            'updatedAt' => 'Дата обновления',
            'image' => 'картинка',
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getDescriptions()
    {
        return $this->hasMany(Description::className(), ['tourId' => 'id']);
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getCategory()
    {
        return $this->hasOne(Categories::className(), ['id' => 'categoryId']);
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getCategory0()
    {
        return $this->hasOne(Categories::className(), ['id' => 'categoryId']);
    }

    public function toArray(array $fields = [], array $expand = [], $recursive = true)
    {
        $data = parent::toArray($fields, $expand, $recursive);

        if (strlen($data['image']) > 0) {
            $data['image'] = Yii::$app->request->hostInfo . $data['image'];
        }

        return $data;
    }
}
