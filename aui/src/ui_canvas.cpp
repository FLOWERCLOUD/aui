/**
 * @file    ui_canvas.cpp
 * @brief   �����ӿڶ�����
 * @author  xiangwangfeng <xiangwangfeng@gmail.com>
 * @data	2012-6-24
 * @website www.xiangwangfeng.com
 */
#include "ui_canvas.h"

UICanvas *gCanvas = NULL;

UICanvas* CurrentCanvas()
{
	return gCanvas;
}

void	SetCurrentCanvas(UICanvas *canvas)
{
	gCanvas = canvas;
}