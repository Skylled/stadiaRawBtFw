// 600d194a  FUN_600d194a  size=132 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600569e4 FUN_600569e4
//   600d3256 FUN_600d3256
//   600d332a FUN_600d332a
//   600d15e4 thunk_EXT_FUN_000080d8
//   600d26ea FUN_600d26ea


undefined4 FUN_600d194a(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 3;
  }
  else {
    if (param_2 == (undefined4 *)0x0) {
      FUN_600569e4();
    }
    else {
      uVar2 = param_4;
      if (param_2[10] != 0) {
        FUN_600d332a(*param_2,param_2[10],0,param_4,param_4);
        uVar2 = param_4;
        FUN_600d3256(*param_2,param_2[10]);
        param_4 = 0;
        param_2[10] = 0;
      }
      if (param_2[0xb] != 0) {
        FUN_600d332a(*param_2,param_2[0xb],0,param_4,uVar2);
        FUN_600d3256(*param_2,param_2[0xb]);
        param_2[0xb] = 0;
      }
      iVar1 = FUN_600d26ea(*param_2,param_1);
      if (iVar1 == 0) {
        FUN_600569e4(param_1,param_2[2]);
      }
      if ((param_2[0x14] != 0) && (param_2[0x17] != 0)) {
        FUN_600d332a(*param_2);
      }
      iVar1 = FUN_600d26ea(*param_2,param_1);
      if (iVar1 == 0) {
        FUN_600569e4(param_1,param_2[3]);
      }
      thunk_EXT_FUN_000080d8(param_2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


