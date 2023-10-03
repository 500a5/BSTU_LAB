<?php

namespace app\modules\api\controllers;

class OrderController extends BaseController
{
    public function verbs()
    {
        return [
            'cart' => ['POST', 'OPTIONS']
        ];
    }

    /**
     * Обрабатываем оформление заказа.
     *
     * @return array
     */
    public function actionCart()
    {
        $data = \Yii::$app->request->getBodyParams();
        return ['status' => 'success'];
    }
}