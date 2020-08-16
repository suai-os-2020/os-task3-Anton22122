#include "lab3.h"
#include "windows.h"


unsigned int lab3_thread_graph_id() {
    return 7;
}

const char *lab3_unsynchronized_threads() {
    return "dfgi";
}

const char *lab3_sequential_threads() {
    return "bcdg";
}

DWORD ThreadID;
HANDLE aThread[11];
HANDLE lock;
HANDLE sem_a, sem_b, sem_c, sem_d, sem_e, sem_f, sem_g,
    sem_i, sem_k, sem_m, sem_n, sem_bSync, sem_cSync, sem_dSync, sem_gSync;


DWORD WINAPI thread_a(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'a' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_a, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_b(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_a, INFINITE);
    ReleaseSemaphore(sem_gSync, 1, NULL);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(sem_gSync, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'b' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(sem_bSync, 1, NULL);
    }
    WaitForSingleObject(sem_gSync, INFINITE);
    ReleaseSemaphore(sem_b, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_c(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_a, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(sem_bSync, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'c' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(sem_cSync, 1, NULL);
    }
    ReleaseSemaphore(sem_c, 3, NULL);
    WaitForSingleObject(sem_b, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'c' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_c, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_d(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_a, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(sem_cSync, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'd' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(sem_dSync, 1, NULL);
    }
    ReleaseSemaphore(sem_d, 3, NULL);
    WaitForSingleObject(sem_b, INFINITE);
    WaitForSingleObject(sem_c, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'd' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_d, 3, NULL);
    WaitForSingleObject(sem_e, INFINITE);
    WaitForSingleObject(sem_c, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'd' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_d, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_e(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_b, INFINITE);
    WaitForSingleObject(sem_c, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'e' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_e, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_f(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_e, INFINITE);
    WaitForSingleObject(sem_c, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'f' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_f, 4, NULL);
    return TRUE;
}
DWORD WINAPI thread_g(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_a, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(sem_dSync, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(sem_gSync, 1, NULL);
    }
    ReleaseSemaphore(sem_g, 3, NULL);
    WaitForSingleObject(sem_b, INFINITE);
    WaitForSingleObject(sem_c, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_g, 3, NULL);
    WaitForSingleObject(sem_e, INFINITE);
    WaitForSingleObject(sem_c, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_g, 3, NULL);
    WaitForSingleObject(sem_f, INFINITE);
    WaitForSingleObject(sem_i, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'g' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_g, 2, NULL);
    return TRUE;
}
DWORD WINAPI thread_i(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_e, INFINITE);
    WaitForSingleObject(sem_c, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'i' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_i, 3, NULL);
    WaitForSingleObject(sem_f, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'i' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_i, 2, NULL);
    return TRUE;
}
DWORD WINAPI thread_k(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_f, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    WaitForSingleObject(sem_i, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'k' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_k, 2, NULL);
    return TRUE;
}
DWORD WINAPI thread_m(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_f, INFINITE);
    WaitForSingleObject(sem_d, INFINITE);
    WaitForSingleObject(sem_i, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'm' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    ReleaseSemaphore(sem_m, 1, NULL);
    WaitForSingleObject(sem_i, INFINITE);
    WaitForSingleObject(sem_k, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'm' << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    return TRUE;
}
DWORD WINAPI thread_n(LPVOID lpParam) {
    UNREFERENCED_PARAMETER(lpParam);
    WaitForSingleObject(sem_k, INFINITE);
    WaitForSingleObject(sem_i, INFINITE);
    WaitForSingleObject(sem_g, INFINITE);
    WaitForSingleObject(sem_m, INFINITE);
    for (int i = 0; i < 3; i++) {
        WaitForSingleObject(lock, INFINITE);
        std::cout << 'n' << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return TRUE;
}
int initMutex(){
	lock = CreateMutex(NULL, FALSE, NULL);
    if (lock == NULL) {
        std::cerr << "CreateMutex error: " << GetLastError() << '\n';
        return 1;
    }
    return 0;
}
int initSem(){
	sem_a = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_a == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_b = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_b == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_c = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_c == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_d = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_d == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_e = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_e == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_f = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_f == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_g = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_g == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_i = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_i == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_k = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_k == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_m = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_m == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_n = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_n == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_bSync = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_bSync == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_cSync = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_cSync == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_dSync = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_dSync == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    sem_gSync = CreateSemaphore(NULL, 0, 11, NULL);
    if (sem_gSync == NULL){
        std::cerr << "CreateSemaphore error: " << GetLastError() << '\n'; return 1;}
    return 0;
}
int initThread(){
	aThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_a, NULL, 0, &ThreadID);
    if (aThread[0] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_b, NULL, 0, &ThreadID);
    if (aThread[1] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_c, NULL, 0, &ThreadID);
    if (aThread[2] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[3] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_d, NULL, 0, &ThreadID);
    if (aThread[3] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[4] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_e, NULL, 0, &ThreadID);
    if (aThread[4] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[5] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_f, NULL, 0, &ThreadID);
    if (aThread[5] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[6] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_g, NULL, 0, &ThreadID);
    if (aThread[6] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[7] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_i, NULL, 0, &ThreadID);
    if (aThread[7] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[8] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_k, NULL, 0, &ThreadID);
    if (aThread[8] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[9] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_m, NULL, 0, &ThreadID);
    if (aThread[9] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    aThread[10] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_n, NULL, 0, &ThreadID);
    if (aThread[10] == NULL) {
        std::cerr << "CreateThread error: " << GetLastError() << '\n'; return 1;
    }
    return 0;
}
int lab3_init() {

    initMutex();
	initSem();
    initThread();
    WaitForMultipleObjects(11, aThread, TRUE, INFINITE);
    CloseHandle(lock);
    for (int i = 0; i < 11; i++)
        CloseHandle(aThread[i]);
    CloseHandle(sem_a);
    CloseHandle(sem_b);
    CloseHandle(sem_c);
    CloseHandle(sem_d);
    CloseHandle(sem_e);
    CloseHandle(sem_f);
    CloseHandle(sem_g);
    CloseHandle(sem_i);
    CloseHandle(sem_k);
    CloseHandle(sem_m);
    CloseHandle(sem_n);
    return 0;
}
