<?php

namespace app\models;

use Yii;

/**
 * This is the model class for table "Categories".
 *
 * @property int $id
 * @property string $name Наименование
 * @property string $createdAt Дата создания
 * @property string|null $updatedAt Дата обновления
 */
class Category extends BaseModel
{
    /**
     * {@inheritdoc}
     */
    public static function tableName()
    {
        return 'Categories';
    }

    /**
     * {@inheritdoc}
     */
    public function rules()
    {
        return [
            [['name', 'createdAt'], 'required'],
            [['createdAt', 'updatedAt'], 'safe'],
            [['name'], 'string', 'max' => 128],
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'name' => 'Наименование',
            'createdAt' => 'Дата создания',
            'updatedAt' => 'Дата обновления',
        ];
    }
}
