<?php

$params = require __DIR__ . '/params.php';
$db = require __DIR__ . '/db.php';

$config = [
    'id' => 'basic',
    'basePath' => dirname(__DIR__),
    'bootstrap' => ['log'],
    'aliases' => [
        '@bower' => '@vendor/bower-asset',
        '@npm'   => '@vendor/npm-asset',
    ],
    'components' => [
        'request' => [
            // !!! insert a secret key in the following (if it is empty) - this is required by cookie validation
            'parsers' => [
                'application/json'=>'yii\web\JsonParser',
                'multipart/form-data' => 'yii\web\MultipartFormDataParser'
            ],
            'cookieValidationKey' => 'nfyL2f02rUU4-0w_wAnU6BbPbH2Ukxte',
        ],
        'cache' => [
            'class' => 'yii\caching\FileCache',
        ],
        'user' => [
            'identityClass' => 'app\models\User',
            'enableAutoLogin' => true,
        ],
        'errorHandler' => [
            'errorAction' => 'site/error',
        ],
        'mailer' => [
            'class' => 'yii\swiftmailer\Mailer',
            // send all mails to a file by default. You have to set
            // 'useFileTransport' to false and configure a transport
            // for the mailer to send real emails.
            'useFileTransport' => true,
        ],
        'log' => [
            'traceLevel' => YII_DEBUG ? 3 : 0,
            'targets' => [
                [
                    'class' => 'yii\log\FileTarget',
                    'levels' => ['error', 'warning'],
                ],
            ],
        ],
        'db' => $db,

        'urlManager' => [
            'enablePrettyUrl' => true,
            'showScriptName' => false,
            'rules' => [
                'POST api/<controller>/registry' => 'api/<controller>/registry',

                'POST api/<controller>/record' => 'api/<controller>/record',
                'GET api/description/<tourId:\d+>' => 'api/description/index',
                'GET api/<controller>/<id:\d+>' => 'api/<controller>/view',

                'api/<controller>/<action>' => 'api/<controller>/<action>'
            ],
        ],
    ],
    'params' => $params,
    'modules' => [
        'api' => [
            'class' => 'app\modules\api\ApiModule'
        ],
        'admin' => [
            'class' =>'app\modules\api\AdminModule'
        ]
    ]
];

if (YII_ENV_DEV) {
    // configuration adjustments for 'dev' environment
    $config['bootstrap'][] = 'debug';
    $config['modules']['debug'] = [
        'class' => 'yii\debug\Module',
        // uncomment the following to add your IP if you are not connecting from localhost.
        'allowedIPs' => ['127.0.0.1', '*'],
    ];

    $config['bootstrap'][] = 'gii';
    $config['modules']['gii'] = [
        'class' => 'yii\gii\Module',
        // uncomment the following to add your IP if you are not connecting from localhost.
        'allowedIPs' => ['127.0.0.1', '*'],
    ];
}

return $config;
