/**
 * @file    gdi_canvas.h
 * @brief   GDI����
 * @author  xiangwangfeng <xiangwangfeng@gmail.com>
 * @data	2012-4-22
 * @website www.xiangwangfeng.com
 */

#pragma once
#include <Windows.h>
#include "ui_canvas.h"

class CxImage;

class GDICanvas: public UICanvas
{
public:
	GDICanvas(HDC hdc,int width,int height);
	~GDICanvas();

public:
	virtual void	FillRect(const UIRect *rect,UIColor color);		//������
	virtual	void	Rectangle(const UIRect *rect,UIColor color);	//���Ʊ߿�
	virtual void	SelectClipedRect(const UIRect *rect);			//ѡ��ü�����
	virtual void	DrawImage(const std::wstring &filepath,const UIRect *src,const UIRect *dst); //����ͼ��
	virtual void	DrawImage(const std::wstring &filepath,const UIRect *dst); //����ͼ��
	virtual	void	DrawText(const wchar_t *text,size_t text_length,const UIRect *rect,UIColor text_color,UINT format,const UIFont *font = NULL);//��������
private:
	HDC	hdc_;			
	HDC mem_hdc_;		
	HBITMAP bitmap_;	
	HBITMAP old_bitmap_;
	int	width_;			
	int height_;
};
