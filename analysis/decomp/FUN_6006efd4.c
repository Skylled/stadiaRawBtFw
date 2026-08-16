// 6006efd4  FUN_6006efd4  size=64 bytes
// --- callers ---
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   60060040 FUN_60060040
//   6005f534 FUN_6005f534
//   6005fe04 io_pin__6005fe04


void FUN_6006efd4(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_1;
  FUN_60060040(DAT_6006f014,*puVar2,puVar2[1],puVar2[2],puVar2[3],puVar2[4],puVar2[5],puVar2[6],
               param_1);
  iVar1 = *param_1;
  io_pin__6005fe04(iVar1);
  FUN_6005f534(iVar1 + 0x2c);
  return;
}


