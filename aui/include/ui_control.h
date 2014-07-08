/**
 * @file    ui_control.h
 * @brief   UI�ؼ�����
 * @author  xiangwangfeng <xiangwangfeng@gmail.com>
 * @data	2012-4-22
 * @website www.xiangwangfeng.com
 */
#pragma once
#include <string>
#include <vector>
#include "ui_base.h"

//��λ��ʽ
enum Alignment
{
//���Զ�λ
	kAlignmentLeftTop,
	kAlignmentLeftCenter,
	kAlignmentLeftBottom,
	kAlignmentCenterTop,
	kAlignmentCenter,
	kAlignmentCenterBottom,
	kAlignmentRightTop,
	kAlignmentRightCenter,
	kAlignmentRightBottom,
//��Զ�λ
	kAlignmentLeft,
	kAlignmentRight,
	kAlignmentTop,
	kAlignmentBottom,
	kAlignmentFill,
};

class UICanvas;
class UIWindow;
class UIControl;



class UIControl
{
public:
	UIControl();
	virtual ~UIControl();
	void	SetAttribute(const char *name,const char *value);
public:
	//�ؼ���
	void			SetControlName(const char *name);
	std::string		GetControlName() const;
	//Tagֵ
	void		SetTag(int tag);
	int			GetTag() const;
	//�ؼ���߾�
	void		SetMargin(const UIMargin &margin);
	void		SetMargin(int left,int top = 0,int right = 0,int bottom = 0);
	//�ؼ���С
	void		SetSize(const UISize &size);
	void		SetSize(int width,int height);
	UISize		GetSize() const;
	//�ؼ���λ��ʽ
	void		SetAlignmentType(Alignment type);
	Alignment	GetAlignmentType() const;
	//�ؼ��ɼ���
	void		SetVisible(BOOL visible);
	BOOL		IsVisible() const;
	//�ؼ�������
	void		SetEnabled(BOOL enabled);
	BOOL		IsEnabled() const;
	//���ؼ�
	void		SetParent(UIControl *control);
	UIControl*	GetParent() const;
	//���/�Ƴ��ӿؼ�
	void		AddSubControl(UIControl *control);
	void		RemoveSubControl(const std::string &name);
	//����
	virtual	void	RenderSelf(const UIRect *rect);
	//���Ű�
	virtual	void	ArrangeSelf(const UIRect *parent_frame);
	//����
	UIControl*	LookupMouseFocusedControl(const UIPoint &point);
	//����frame
	void		SetRootFrame(const UIRect *rect);
	void		SetFrame(const UIRect *rect);
	UIRect		GetFrame() const;
	//���ø�����
	void	SetParentWin(UIWindow *window);
	UIWindow*	GetParentWin(); 
	//������Ҫ���ƺ�������Ҫ���Ű�
	void	SetNeedDisplay();
	void	SetNeedLayout();
	//���ù��״̬
	void	SetCursor(const wchar_t *cursor_name);
	//�����Ϣ
	virtual	BOOL	OnMouseMessage(UINT message,WPARAM wParam,LPARAM lParam);
	virtual	void	OnMouseEntered(UINT flag,const UIPoint &point);
	virtual	void	OnMouseExited(UINT flag,const UIPoint &point);
	//��������Ϣ
	virtual	BOOL	OnLButtonDown(UINT flag,const UIPoint &point);
	virtual	BOOL	OnLButtonUp(UINT flag,const UIPoint &point);
	virtual	BOOL	OnLButtonDoubleClicked(UINT flag,const UIPoint &point);
	//����Ҽ���Ϣ
	virtual	BOOL	OnRButtonDown(UINT flag,const UIPoint &point);
	virtual	BOOL	OnRButtonUp(UINT flag,const UIPoint &point);
	virtual	BOOL	OnRButtonDoubleClicked(UINT flag,const UIPoint &point);
	//����м���Ϣ
	virtual	BOOL	OnMButtonDown(UINT flag,const UIPoint &point);
	virtual	BOOL	OnMButtonUp(UINT flag,const UIPoint &point);
	virtual	BOOL	OnMButtonDoubleClicked(UINT flag,const UIPoint &point);
	//������
	virtual void	OnMouseWheel(UINT flag, short delta,const UIPoint &point);
	//����ƶ�
	virtual	BOOL	OnMouseMove(UINT flag,const UIPoint &point);
protected:
	//����֪ͨ�¼�
	void	SendNotify(UINotifyEvent event);
private:
	//����
	void	Render(const UIRect *parent_rect);
	//���Ű�;
	void	Arrange(const UIRect *parent_frame);
	void	ArrangeChildren(const UIRect *parent_frame);
	//���õݹ������ӿؼ��ĸ��׿ɼ��ԺͿ�����
	void	SetParentVisibleRecursive(BOOL visible);
	void	SetParentEnabledRecursive(BOOL enabled);
	//�Ƿ��ڵ�ǰ�ؼ���
	BOOL		IsMouseInControl(const UIPoint &point);
	//�ɷ������Ϣ
	void		DispatchMouseMessage(UINT message,WPARAM wParam,LPARAM lParam);
	//ͨ�����Է���Alignment
	Alignment	GetAlignmentByString(const char *value);
protected:
	std::vector<UIControl *>	children_;		//�ӿؼ�
	UISize						size_;			//�ؼ���С
	Alignment					alignment_type_;//��λ��ʽ
	UIMargin					margin_;		//��߾�
	UIRect						frame_;			//�ڴ����ϵľ���λ��
	UIControl					*parent_;		//���ؼ�
	UIWindow					*parent_win_;	//������
	std::string					name_;			//�ؼ���
	int							tag_;			//tagֵ
	BOOL						visible_;		//�Ƿ�ɼ�
	BOOL						parent_visible_;//�����Ƿ�ɼ�
	BOOL						enabled_;		//�Ƿ����
	BOOL						parent_enabled_;//�����Ƿ����
	
	friend	UIControl;
	friend	UIWindow;
};