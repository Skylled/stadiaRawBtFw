// 60101848  FUN_60101848  size=150 bytes
// --- callers ---
//   60100d98 FUN_60100d98
//   60100c48 FUN_60100c48
//   600cb270 FUN_600cb270
//   600d4664 FUN_600d4664
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572


uint FUN_60101848(int *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  code *pcVar5;
  undefined1 auStack_30 [20];
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  if ((param_2 == (param_2 / uVar1) * uVar1) &&
     (uVar1 = (**(code **)(*param_1 + 0x10))(param_1), uVar1 < 0x11)) {
    thunk_EXT_FUN_0000b5ba(auStack_30,0,0x10);
    iVar2 = (**(code **)(*param_1 + 0x10))(param_1);
    iVar2 = param_4 - (param_4 / iVar2) * iVar2;
    uVar4 = param_4 - iVar2 & 0xffff;
    uVar1 = (**(code **)(*param_1 + 8))(param_1,param_2,param_3,uVar4);
    if ((uVar1 & 0xff) == 0) {
      if (iVar2 != 0) {
        thunk_EXT_FUN_0000b572(auStack_30,param_3 + uVar4,iVar2);
        pcVar5 = *(code **)(*param_1 + 8);
        uVar3 = (**(code **)(*param_1 + 0x10))(param_1);
        uVar1 = (*pcVar5)(param_1,uVar4 + param_2,auStack_30,uVar3);
        if ((uVar1 & 0xff) != 0) {
          return uVar1;
        }
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}


