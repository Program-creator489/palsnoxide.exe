DWORD WINAPI RGB1(LPVOID lpParam)
{
	while (1) {
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(SM_CXSCREEN),
			h = GetSystemMetrics(SM_CYSCREEN);

		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, brush);
		PatBlt(hdc, 0, 0, w, h, PATINVERT);
		DeleteObject(brush);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI RGB2(LPVOID lpParam) {
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (1) {
		HDC hdc = GetDC(0);
		BitBlt(hdc, 0, 0, w, h, hdc, -30, 0, SRCCOPY);
		BitBlt(hdc, 0, 0, w, h, hdc, w - 30, 0, SRCCOPY);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, -30, SRCCOPY);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, h - 30, SRCCOPY);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, brush);
		BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, PATINVERT);
		DeleteObject(brush);
		ReleaseDC(0, hdc);
		Sleep(10);
	}
}
DWORD WINAPI payload1(LPVOID lpParam)
{
	while (1) {
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(SM_CXSCREEN),
			h = GetSystemMetrics(SM_CYSCREEN);
		StretchBlt(hdc, 10, 10, w - 20, h - 20, hdc, 0, 0, w, h, SRCINVERT);
		StretchBlt(hdc, -10, -10, w + 20, h + 20, hdc, 0, 0, w, h, SRCINVERT);
		ReleaseDC(NULL, hdc);
	}
}
DWORD WINAPI payload2(LPVOID lpParam) {
	HDC desktop = GetDC(NULL);
	int xs = GetSystemMetrics(SM_CXSCREEN);
	int ys = GetSystemMetrics(SM_CYSCREEN);
	while (true) {
		desktop = GetDC(NULL);
		BitBlt(desktop, 0, 0, xs, ys, desktop, -1, -1, SRCERASE);
		ReleaseDC(0, desktop);
		Sleep(10);
	}
}