/**
 * @file    ui_panel.h
 * @brief   UIPanel
 * @author  xiangwangfeng <xiangwangfeng@gmail.com>
 * @data	2012-6-20
 * @website www.xiangwangfeng.com
 */
#pragma once
#include "ui_control.h"

class UIPanel : public UIControl
{
public:	
	//����ɫ
	void	SetBKColor(UIColor color);
	//����ͼƬ
	void	SetBKImage(const std::wstring &filepath);
public:
	virtual	void	RenderSelf(const UIRect *rect);

private:
	UIColor			bk_color_;
	std::wstring	bk_filepath_;
};
