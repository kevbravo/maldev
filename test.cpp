#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>

using namespace std;

int main(){

    vector<unsigned char> const code = {

        0xb8,
        0x05, 0x00, 0x00, 0x00,
        0xc3
    };

    auto const exec = VirtualAlloc(0, code.size(), MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    memcpy(exec, code.data(), code.size());

    DWORD dummy;

    VirtualProtect(exec, code.size(), PAGE_EXECUTE_READWRITE, &dummy);
    
    int result = ((int(*)())exec)();

    cout << "success" << endl;

    cout << result;

    return 0;
}
