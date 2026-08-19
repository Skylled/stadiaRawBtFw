// 600d8e6c  FUN_600d8e6c  size=104 bytes
// --- callers ---
//   600d8f64 FUN_600d8f64
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   6006b350 usb_port_controller_tusb320__6006b350
//   600d8ed4 FUN_600d8ed4
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   6013d3d8 thunk_EXT_FUN_0000b4c2


char FUN_600d8e6c(int param_1,undefined1 param_2,undefined1 *param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  undefined1 local_30 [4];
  undefined1 local_2c [8];
  
  bVar2 = 0;
  thunk_EXT_FUN_0000b4c2(param_1 + 200);
  while (local_30[0] = param_2,
        cVar1 = thunk_EXT_FUN_00001ea4
                          (*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),local_30,
                           1,local_2c,1,200), cVar1 != '\0') {
    if ((cVar1 != '\x04') || (bVar2 = bVar2 + 1, param_4 < bVar2)) goto LAB_600d8eae;
  }
  *param_3 = local_2c[0];
LAB_600d8eae:
  thunk_EXT_FUN_00007d10(param_1 + 200);
  return cVar1;
}


