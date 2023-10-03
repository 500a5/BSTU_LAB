<?php


namespace app\models;
use yii\base\Model;

class RecordForm extends Model
{
    public $name;
    public $email;
    public $phone;
    public $categoryId;

    public function rules()
    {
        return [
            [['name', 'email', 'phone', 'categoryId'], 'required'],
            ['email','email'],
            [['createdAt','updatedAt'],'safe']
        ];
    }
    public function record()
    {
        $table = new Record();
        $table->name = $this->name;
        $table->email = $this->email;
        $table->phone = $this->phone;
        $table->categoryId = $this->categoryId;
        $table->save();
    }
}