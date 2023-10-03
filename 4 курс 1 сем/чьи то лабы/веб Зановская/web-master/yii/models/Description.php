<?php

namespace app\models;

use Yii;

/**
 * This is the model class for table "Description".
 *
 * @property int $id
 * @property string|null $description описание
 * @property int $tourId категория тура
 * @property string|null $image картинка
 * @property string $createdAt
 * @property string|null $updatedAt
 *
 * @property Tours $tour
 */
class Description extends BaseModel
{
    /**
     * {@inheritdoc}
     */
    public static function tableName()
    {
        return 'Description';
    }

    /**
     * {@inheritdoc}
     */
    public function rules()
    {
        return [
            [['description'], 'string'],
            [['tourId', 'createdAt'], 'required'],
            [['tourId'], 'integer'],
            [['createdAt', 'updatedAt'], 'safe'],
            [['image'], 'string', 'max' => 128],
            [['tourId'], 'exist', 'skipOnError' => true, 'targetClass' => Tours::className(), 'targetAttribute' => ['tourId' => 'id']],
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function attributeLabels()
    {
        return [
            'id' => 'ID',
            'description' => 'описание',
            'tourId' => 'категория тура',
            'image' => 'картинка',
            'createdAt' => 'Created At',
            'updatedAt' => 'Updated At',
        ];
    }

    /**
     * @return \yii\db\ActiveQuery
     */
    public function getTour()
    {
        return $this->hasOne(Tours::className(), ['id' => 'tourId']);
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
