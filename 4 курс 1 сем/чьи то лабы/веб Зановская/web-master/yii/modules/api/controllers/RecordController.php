<?php

namespace app\modules\api\controllers;
use Yii;
use app\models\RecordForm;

class RecordController extends BaseActiveController
{
    public $modelClass = 'app\models\Record';
    public function verbs()
    {
        return [
            'record' => ['POST', 'OPTIONS']
        ];
    }

    /**
     * Обрабатываем оформление заказа.
     *
     * @return array
     */
    public function actionRecord()
    {
        $model = new RecordForm();
        $model->load(Yii::$app->request->getBodyParams(),'');
        if ($model->validate()){
            $model->record();
            return ['status' => 'success'];
        }
        return $model;
    }
}