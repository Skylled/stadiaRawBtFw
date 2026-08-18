// 600d0f14  FUN_600d0f14  size=162 bytes
// --- callers ---
//   600d109c FUN_600d109c
//   600d1090 FUN_600d1090
// --- callees ---
//   600d15e8 FUN_600d15e8
//   6013d3e0 thunk_EXT_FUN_00008802
//   6013d318 thunk_EXT_FUN_00000fac
//   60052428 FUN_60052428


int FUN_600d0f14(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 *puVar4;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 3;
  }
  else if (param_1[1] == 0) {
    iVar1 = 6;
  }
  else {
    uVar2 = (param_2 >> 7 | param_2 << 1) & 0xff;
    if (*(char *)(param_1 + uVar2 * 3 + 5) == '\0') {
      puVar4 = param_1;
      uStack_24 = param_2;
      uStack_20 = param_3;
      thunk_EXT_FUN_00008802((int)&uStack_24 + 3);
      *(undefined1 *)(param_1 + uVar2 * 3 + 5) = 1;
      FUN_600d15e8(uStack_24._3_1_);
      if ((param_2 & 0x80) == 0) {
        if (param_4 != 0) {
          FUN_60052428(param_3,param_4);
        }
        pcVar3 = *(code **)(param_1[1] + 0xc);
      }
      else {
        if (param_4 != 0) {
          thunk_EXT_FUN_00000fac(param_3,param_4);
        }
        pcVar3 = *(code **)(param_1[1] + 8);
      }
      iVar1 = (*pcVar3)(*param_1,param_2,param_3,param_4,puVar4);
      if (iVar1 != 0) {
        thunk_EXT_FUN_00008802((int)&uStack_24 + 3);
        *(undefined1 *)(param_1 + uVar2 * 3 + 5) = 0;
        FUN_600d15e8(uStack_24._3_1_);
      }
    }
    else {
      iVar1 = 2;
    }
  }
  return iVar1;
}


