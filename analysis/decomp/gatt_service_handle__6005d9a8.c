// 6005d9a8  gatt_service_handle__6005d9a8  size=28 bytes
// src: gatt_service_handle.h
// --- callers ---
//   600df4c4 FUN_600df4c4
// --- callees ---
//   601016a2 FUN_601016a2


/* src: gatt_service_handle.h */

undefined4 gatt_service_handle__6005d9a8(int param_1)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_601016a2(PTR_s_gatt_service_handle_h_6005d9cc,0x18c,PTR_s__s_60127a03_0x13_6005d9c8,
                 PTR_s_CHECK_failed_60122ce9_9_6005d9c4);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
}


