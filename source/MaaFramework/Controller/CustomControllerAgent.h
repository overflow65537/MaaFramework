#pragma once
#include "ControllerAgent.h"
#include "MaaFramework/Instance/MaaCustomController.h"
#include "MaaFramework/MaaDef.h"

MAA_CTRL_NS_BEGIN

class CustomControllerAgent : public ControllerAgent
{
public:
    CustomControllerAgent(
        MaaCustomControllerCallbacks* controller,
        void* controller_arg,
        MaaNotificationCallback notify,
        void* notify_trans_arg);
    virtual ~CustomControllerAgent() override = default;

protected:
    virtual bool _connect() override;
    virtual std::optional<std::string> _request_uuid() override;
    virtual bool _start_app(AppParam param) override;
    virtual bool _stop_app(AppParam param) override;
    virtual std::optional<cv::Mat> _screencap() override;
    virtual bool _click(ClickParam param) override;
    virtual bool _swipe(SwipeParam param) override;
    virtual bool _multi_swipe(std::vector<SwipeParam> param) override;
    virtual bool _touch_down(TouchParam param) override;
    virtual bool _touch_move(TouchParam param) override;
    virtual bool _touch_up(TouchParam param) override;
    virtual bool _press_key(PressKeyParam param) override;
    virtual bool _input_text(InputTextParam param) override;

private:
    MaaCustomControllerCallbacks* controller_ = nullptr;
    void* controller_arg_ = nullptr;
};

MAA_CTRL_NS_END
