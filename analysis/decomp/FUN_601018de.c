// 601018de  FUN_601018de  size=144 bytes
// --- callers ---
//   600cb6fc key_value_store__600cb6fc
//   6005e3d0 bug_report__6005e3d0
//   600cb598 key_value_store__600cb598
//   6005e58c bug_report__6005e58c
//   600cb460 key_value_store__600cb460
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


uint FUN_601018de(int *param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  code *pcVar5;
  undefined1 auStack_30 [20];
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  if ((param_3 == (param_3 / uVar1) * uVar1) &&
     (uVar1 = (**(code **)(*param_1 + 0x10))(param_1), uVar1 < 0x11)) {
    iVar2 = (**(code **)(*param_1 + 0x10))(param_1);
    iVar2 = param_4 - (param_4 / iVar2) * iVar2;
    uVar4 = param_4 - iVar2 & 0xffff;
    uVar1 = (**(code **)(*param_1 + 4))(param_1,param_2,param_3,uVar4);
    if ((uVar1 & 0xff) == 0) {
      if (iVar2 != 0) {
        pcVar5 = *(code **)(*param_1 + 4);
        uVar3 = (**(code **)(*param_1 + 0x10))(param_1);
        uVar1 = (*pcVar5)(param_1,auStack_30,param_3 + uVar4,uVar3);
        if ((uVar1 & 0xff) != 0) {
          return uVar1;
        }
        thunk_EXT_FUN_0000b572(param_2 + uVar4,auStack_30,iVar2);
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
}


