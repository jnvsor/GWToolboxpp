#pragma once

#include "Process.h"

enum InjectReply
{
    InjectReply_Inject,
    InjectReply_Cancel,
    InjectReply_NoProcess,
    InjectReply_PatternError,
};

class InjectWindow
{
public:
    static InjectReply AskInjectProcess(Process *process);

private:
    static void OnWindowCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    InjectWindow();
    InjectWindow(const InjectWindow&) = delete;
    InjectWindow(InjectWindow&&) = delete;
    ~InjectWindow();

    bool Create(std::vector<std::wstring>& names);
    bool WaitMessages();

    // Returns false if no options were selected, typically when the window was closed.
    bool GetSelected(int *index);

private:
    LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    void OnCommand(HWND hwnd, LONG control_id, LONG notification_code);

private:
    HWND m_hWnd;
    HWND m_hCharacters;
    HWND m_hLaunchButton;
    HWND m_hRestartAsAdmin;
    HWND m_hSettings;
    HFONT m_hFont;
    HANDLE m_hEvent;
    HINSTANCE m_hInstance;

    int m_Selected;
};

bool InjectRemoteThread(Process *process, LPCWSTR ImagePath, LPDWORD lpExitCode);