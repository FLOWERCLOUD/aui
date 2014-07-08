/**
 * @file    ui_window.h
 * @brief   ͨ�ô�����
 * @author  xiangwangfeng <xiangwangfeng@gmail.com>
 * @data	2012-4-22
 * @website www.xiangwangfeng.com
 */

#pragma once
#include <vector>
#include "native_window.h"
#include "ui_base.h"


class UICanvas;
class UIControl;
class IUINotify;

class UIWindow : public NativeWindow
{
public:
	UIWindow();
	~UIWindow();
	//��Ϣѭ��
	virtual LRESULT	HandleMessages(UINT message, WPARAM wParam, LPARAM lParam);
	//��Ӹ��ؼ�
	void	AddRootControl(UIControl *root_control);
	//�Կؼ������Ű�
	void	UpdateLayout();
	//ˢ�½���
	void	Invalidate(const UIRect *rect);
	//���ô��������Сֵ
	void	SetWindowMinSize(const UISize *size);
	void	SetWindowMinSize(int width,int height);
	void	SetWindowMaxSize(const UISize *size);
	void	SetWindowMaxSize(int width,int height);
	//��ӹ۲���
	void	AddNotifier(IUINotify *notifier);
	void	FireEvent(UINotifyEvent event,UIControl *contorl);
	//�̳���NativeWindow�ķ���
	virtual void	OnSize(UINT type,int cx,int cy);
	virtual void	OnGetMinMaxInfo(MINMAXINFO* lpMMI);
private:
	//���Ʒ���
	void	Render(const UIRect *rect);
	//ʵ���Ű淽��
	void	DoUpdateLayout();
	//����WM_PAINT
	void	HandleWMPaintMessage();
	//���������Ϣ
	void	HandleMouseMessage(UINT message,WPARAM wParam,LPARAM lParam);
	//���õ�ǰ���
	void	SetCurrentMouseControl(UIControl *control);
private:
	BOOL		is_closing_;			//���ڹر�
	BOOL		resize_needed_;			//��Ҫ���Ű�
	BOOL		is_mouse_in_;			//����Ƿ��ڴ�����
	UIControl	*current_mouse_control_;//��ǰ��꽹��ؼ�
	UIControl	*root_control_;			//���ڵ�
	UISize		min_size_;				//������С��С
	UISize		max_size_;				//��������С
	std::vector<IUINotify *>	notifiers;
};