<?php

use App\Http\Controllers\DeviceController;
use App\Http\Controllers\DashboardController;
use App\Http\Controllers\AuthController;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\SensorController;
use App\Http\Middleware\AuthCheck;
use App\Http\Middleware\IsAdmin;


Route::middleware('auth-check')->group(function ($router) {
    $router->get('/', [DashboardController::class, 'index']);

    $router->controller(SensorController::class)->group(function ($subrouter) {
        $subrouter->get('/sensor',  'index');
        $subrouter->get('/sensor/create',  'create');
        $subrouter->post('/sensor/store',  'store');
        $subrouter->get('/sensor/edit/{id}',  'edit');
        $subrouter->put('/sensor/update/{id}',  'update');
        $subrouter->delete('/sensor/delete/{id}',  'delete');
    });
});

Route::middleware('is-admin'::class)->group(function ($router) {
    $router->controller(DeviceController::class)->group(function ($subrouter) {
        $subrouter->get('/device',  'index');
        $subrouter->get('/device/create',  'create');
        $subrouter->post('/device/store',  'store');
        $subrouter->get('/device/edit/{id}',  'edit');
        $subrouter->put('/device/update/{id}',  'update');
        $subrouter->delete('/device/delete/{id}',  'delete');
    });
});

Route::get('/ganti-password', [AuthController::class, 'viewChangePassword']);
Route::post('/ganti-password', [AuthController::class, 'changePassword']);
