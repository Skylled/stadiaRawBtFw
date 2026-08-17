// 6005fa80  flash_lut__6005fa80  size=130 bytes
// src: flash_lut.cc
// --- callers ---
//   600d4902 flash_lut__600d4902
// --- callees ---
//   6013d178 thunk_EXT_FUN_00008996
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013cfd0 thunk_EXT_FUN_00000c7c
//   6010165c FUN_6010165c
//   6013d3d8 thunk_EXT_FUN_0000b4c2


/* src: flash_lut.cc */

undefined1 flash_lut__6005fa80(int *param_1,uint param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 != 0) {
    uVar3 = (uint)*(byte *)(param_1 + 3);
    if ((param_2 == uVar3 * (param_2 / uVar3)) && (param_4 == uVar3 * (param_4 / uVar3))) {
      uVar3 = param_2;
      iVar4 = param_3;
      thunk_EXT_FUN_0000b4c2(param_1 + 7);
      if (*(char *)((int)param_1 + 0x19) == '\0') {
        uVar1 = 9;
      }
      else {
        uVar2 = (**(code **)(*param_1 + 0x24))(param_1);
        thunk_EXT_FUN_00000c7c(param_2,param_3,param_4,uVar2,param_1[1] * param_1[2],uVar3,iVar4);
        uVar1 = thunk_EXT_FUN_00008996();
      }
      thunk_EXT_FUN_00007d10(param_1 + 7);
      return uVar1;
    }
    FUN_6010165c(0x28,DAT_6005fb04,0x1be,DAT_6005fb08,param_2,param_4,uVar3,param_4);
  }
  return 3;
}


