<?php


namespace app\modules\api\controllers;


use app\models\Description;
use yii\web\NotFoundHttpException;

class DescriptionController extends BaseController
{
    public function verbs()
    {
        return [
            'index' => ['GET', 'OPTIONS'],
            'view' => ['GET', 'OPTIONS']
        ];
    }

    public function actionIndex($tourId)
    {
        $models = Description::findAll(['tourId' => $tourId]);
        return $models;
    }

    public function actionView($id)
    {
        $model = Description::findOne($id);

        if ($model === null) {
            throw new NotFoundHttpException('Description not found.');
        }

        return $model;
    }
}