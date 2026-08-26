// 600d89a6  FUN_600d89a6  size=70 bytes
// --- callers ---
//   60081a34 FUN_60081a34
// --- callees ---
//   6006a880 gatt_server__6006a880
//   600d8994 FUN_600d8994
//   60095650 FUN_60095650
//   6009598c FUN_6009598c
//   60092edc FUN_60092edc


undefined4 FUN_600d89a6(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600d8994(param_1 + 0x110);
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else {
    FUN_60092edc(0xff,0,0xff);
    if (*(short *)(param_1 + 0x120) != -1) {
      FUN_6009598c();
    }
    gatt_server__6006a880(param_1 + 0x13c);
    FUN_60095650(*(undefined1 *)(param_1 + 0x368));
    uVar2 = 0;
  }
  return uVar2;
}


