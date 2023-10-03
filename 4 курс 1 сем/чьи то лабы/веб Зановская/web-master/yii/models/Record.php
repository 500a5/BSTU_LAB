<?php

namespace app\models;

use Yii;

/**
 * This is the model class for table "records".
 *
 * @property int $id
 * @property string $name Имя
 * @property string $email Email
 * @property string $phone Телефон
 * @property int $categoryId Тур
 * @property string $createdAt Дата создания
 * @property string|null $updatedAt Дата обновления
 *
 * @property Category $category
 */
class Record extends BaseModel
{
    /**
     * {@inheritdoc}
     */
    public static function tableName()
    {
        return 'records';
    }

    /**
     * {@inheritdoc}
     */
    public function rules()
    {
        return [
            [['name', 'email', 'phone', 'categoryId'], 'required'],
            [['categoryId'], 'integer'],
            [['createdAt', 'updatedAt'], 'safe'],
            [['name', 'email', 'phone'], 'string', 'max' => 128],
            [['categoryId'], 'exist', 'skipOnError' => true, 'targetClass' => Category::className(), 'targetAttribute' => ['categoryId' => 'id']],
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'name' => 'Имя',
            'email' => 'Email',
            'phone' => 'Телефон',
            'categoryId' => 'Тур',
            'createdAt' => 'Дата создания',
            'updatedAt' => 'Дата обновления',
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getCategory()
    {
        return $this->hasOne(Category::className(), ['id' => 'categoryId']);
    }
}
