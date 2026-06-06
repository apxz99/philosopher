#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* สร้างตัวแปร Mutex เพื่อใช้ปกป้อง Critical Section */
pthread_mutex_t my_mutex;

/* Shared Resources (ตัวแปรที่ใช้งานร่วมกัน) */
int shared_a = 5;
int shared_b = 7;

/* ฟังก์ชันการทำงานของ Thread (Worker Thread) */
void* process_shared_data(void* arg) {
    /* 🛡️ ก้าวเข้าสู่ Critical Section: ทำการขอ Lock Mutex */
    /* ถ้ามี Thread อื่นล็อกอยู่ Thread นี้จะหยุดรอ (Block) ที่บรรทัดนี้ */
    pthread_mutex_lock(&my_mutex);
    
    /* === จุดนี้คือ Critical Section (ปลอดภัยแล้ว) === */
    shared_a = shared_a + 3;
    shared_b = shared_b - 1;
    printf("Safe access: a = %d, b = %d\n", shared_a, shared_b);
    
    /* หน่วงเวลาจำลองการประมวลผลฮาร์ดแวร์ */
    sleep(1);
    
    /* 🛡️ ทำงานเสร็จแล้ว: ทำการ Unlock คืนกุญแจให้คนอื่นใช้ต่อ */
    pthread_mutex_unlock(&my_mutex);
    /* ======================================= */
    
    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    
    /* 1. เริ่มต้นการทำงานของ Mutex */
    pthread_mutex_init(&my_mutex, NULL);
    
    /* 2. สร้าง Threads หลายๆ ตัวให้ทำงานพร้อมกัน */
    pthread_create(&t1, NULL, process_shared_data, NULL);
    pthread_create(&t2, NULL, process_shared_data, NULL);
    
    /* 3. รอให้ Threads ทั้งหมดทำงานเสร็จ */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    /* 4. ทำลาย Mutex เพื่อคืนทรัพยากรให้ระบบ */
    pthread_mutex_destroy(&my_mutex);
    
    return 0;
}