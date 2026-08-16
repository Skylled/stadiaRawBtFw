// 600cb598  key_value_store__600cb598  size=338 bytes
// src: key_value_store.cc
// --- callers ---
//   600d7032 FUN_600d7032
//   600d382e FUN_600d382e
//   60065eb8 keys__60065eb8
//   600d6f7e FUN_600d6f7e
//   600d708c FUN_600d708c
//   600d6fd8 FUN_600d6fd8
//   600d6eca FUN_600d6eca
//   600662e0 dynamic_buffer__600662e0
//   600d7282 FUN_600d7282
//   600d5066 FUN_600d5066
//   600764fc input_task__600764fc
//   600d39ba FUN_600d39ba
//   600d70e6 FUN_600d70e6
//   600ce2c6 FUN_600ce2c6
//   600d6f24 FUN_600d6f24
// --- callees ---
//   601018de FUN_601018de
//   6013cef0 thunk_EXT_FUN_0000887a
//   600db002 FUN_600db002
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60100e78 FUN_60100e78
//   60100c14 FUN_60100c14
//   60100b24 FUN_60100b24
//   6010165c FUN_6010165c


/* src: key_value_store.cc */

uint key_value_store__600cb598
               (undefined4 *param_1,int param_2,int param_3,uint param_4,ushort param_5)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int extraout_r2;
  uint uVar5;
  uint uVar6;
  undefined4 *local_34;
  short local_30;
  ushort local_2e;
  ushort local_2a;
  
  uVar6 = (uint)param_5;
  if (((param_2 == 0) || (param_3 == 0)) || (uVar2 = FUN_600db002(param_2,0x10), 0xe < uVar2 - 1)) {
    return 3;
  }
  if (uVar6 != (uint)*(byte *)((int)param_1 + 0x59) * (uVar6 / *(byte *)((int)param_1 + 0x59))) {
    FUN_6010165c(0x28,DAT_600cb6f0,0xd8,DAT_600cb6ec);
    return 3;
  }
  local_34 = param_1 + 1;
  thunk_EXT_FUN_0000b4c2();
  if (*(char *)(param_1 + 0x16) == '\0') {
    uVar5 = 9;
    goto LAB_600cb5f8;
  }
  iVar3 = FUN_60100e78(param_1,param_2);
  if ((iVar3 == 100) || (*(char *)((int)param_1 + iVar3 * 0x18 + 0x16e) != '\0')) {
    uVar5 = 5;
    goto LAB_600cb5f8;
  }
  uVar5 = FUN_601018de(*param_1,&local_30,param_1[iVar3 * 6 + 0x5a],8);
  if ((uVar5 & 0xff) != 0) goto LAB_600cb5f8;
  if (local_30 == 0x55aa) {
    if ((int)(uint)(local_2a >> 4) < (int)(uVar6 + param_4)) {
      uVar5 = 3;
      FUN_6010165c(0x28,DAT_600cb6f0,0xf1,DAT_600cb6f4,uVar6,param_4,(uint)(local_2a >> 4));
      goto LAB_600cb5f8;
    }
    uVar1 = *(undefined1 *)((int)param_1 + 0x59);
    iVar3 = FUN_60100b24(uVar1,8,param_1[iVar3 * 6 + 0x5a]);
    iVar4 = FUN_60100b24(uVar1,(byte)local_2a & 0xf);
    uVar5 = FUN_601018de(*param_1,param_3,extraout_r2 + uVar6 + iVar3 + iVar4,param_4);
    if ((uVar5 & 0xff) != 0) goto LAB_600cb5f8;
    if ((uVar6 == 0) && (param_4 == local_2a >> 4)) {
      uVar6 = FUN_60100c14(param_1,param_2,uVar2 & 0xffff,param_3,param_4);
      if (local_2e != uVar6) {
        FUN_6010165c(0x28,DAT_600cb6f0,0x102,DAT_600cb6f8,param_2,(uint)local_2e,uVar6);
        goto LAB_600cb644;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_600cb644:
    uVar5 = 0xf;
  }
LAB_600cb5f8:
  thunk_EXT_FUN_0000887a(&local_34);
  return uVar5;
}


