# PhotoStore
C++ 應用練習，圖片檢視與分類。

目前透過檢視副檔名來判斷是否為圖檔，但我只寫了三種類型，且網路上的教學是說這種方式不安全，人家可能亂改副檔名。

## 按鈕事件

CLI 要使用按鈕事件時，在載入時就要先將這些按鈕先註冊，才能使用。

onKeyDownListener 是可以自行定義的。

```cpp
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
    for each (Control ^ control in this->Controls)
    {
        control->KeyDown += gcnew KeyEventHandler(this, &Form1::onKeyDownListener);
    }
}
```

## 參數不定個數的 macros

下方 MACRO 在使用時，根據給予的參數個數，會呼叫 MACRO_1 或 MACRO_2

<boost/preprocessor/facilities/overload.hpp> 為透過 vcpkg 工具下載

```cpp
#include <boost/preprocessor/facilities/overload.hpp>

#define MACRO_2(a, b) std::cout << a << ' ' << b;
#define MACRO_1(a) MACRO_2(a, "test") // Supply default argument
#define MACRO(...) BOOST_PP_OVERLOAD(MACRO_, __VA_ARGS__)(__VA_ARGS__)

int main()
{
    MACRO(1); // 1 test
}
```

## vcpkg 工具

於 [vcpkg 的 github 頁面](https://github.com/Microsoft/vcpkg) clone 程式碼，下載完成後 Windows 用戶則進入該資料夾，
點擊 bootstrap-vcpkg.bat 來進行 vcpkg 的安裝。

透過以下指令來安裝第三方套件，"vcpkg install" 是固定指令，而 "boost:x86-windows" 則是套件名稱，這個名稱可以上網找自己需要的套件名稱，
或是像我是在 include <boost/preprocessor/facilities/overload.hpp> 的時候，Visual Studio 建議我使用 vcpkg，該行 include 可以將滑鼠移過去，
會有個選項是讓 Visual Studio 替你產生整行安裝所需的指令:)

`D:\Programing\vcpkg> vcpkg install boost:x86-windows`

若你的 Visual Studio 沒有英語的語言套件，可能會發生失敗。透過 Visual Studio Installer 安裝完後再次執行即可。

套件下載完成後，要透過 `vcpkg integrate install` 這行指令來將 vcpkg 與 Visual Studio 產生連結，在這之後，才能使用剛才所下載的套件。

參考網站1，即 microsoft 官方文件，內容提到的 CMake 專案什麼的，在執行  `vcpkg integrate install` 之前，下載下來的套件內好像也有 .cmake 檔，
還為此找了如何透過 CMake 來產生程式碼，但好像沒啥必要。現在也還是不太了解 CMake 在幹嘛。

* [參考網站1](https://docs.microsoft.com/en-us/cpp/build/vcpkg?view=vs-2019)
* [參考網站2](https://michaelchen.tech/windows-programming/use-vcpkg-to-install-gtk-on-windows/#%E5%AE%89%E8%A3%9D-vcpkg)

## macros 筆記1

當要透過 #define 來定義 Debug::WriteLine(String::Format("XXX")) 時會發生錯誤，會說 `class String 沒有成員 Format`，原本正常運作的程式碼也會報出相同的錯誤，
或許是 #define 定義的地方，尚不能使用 String::Format?

但可透過在函式中使用 String::Format 再在 #define 當中呼叫此函式，還是可以使用 String::Format，只是定義的地方需要調整。

## array & List

array 好像是需要在建立時給定陣列大小，不像 List 可以動態增加減少，且 List 可透過 .ToArray() 轉換成 array。