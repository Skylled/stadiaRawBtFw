// 60042050  FUN_60042050  size=254 bytes
// --- callers ---
// --- callees ---
//   600477e4 queue__600477e4
//   600473e4 queue__600473e4
//   6004be84 thunk_FUN_600d3b3a
//   60047290 queue__60047290
//   6004bf04 thunk_FUN_600d415c
//   6004c444 thunk_FUN_600d37ac
//   6004c294 queue__600c9f94
//   6004c41c thunk_FUN_601016f0


undefined4 FUN_60042050(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int local_b0;
  uint local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  
  local_b0 = param_2;
  local_ac = param_3;
  if (param_2 == *(int *)(param_1 + 100)) {
    switch(param_2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
      uVar2 = *(uint *)(param_1 + 0x68);
      break;
    case 7:
      param_3 = param_3 & 0xff;
      uVar2 = (uint)*(byte *)(param_1 + 0x68);
      break;
    case 10:
      goto switchD_60042068_caseD_a;
    default:
      goto switchD_60042068_default;
    }
    if (param_3 == uVar2) {
switchD_60042068_caseD_a:
      if ((*(uint *)(DAT_6004215c + 4) & 0x1ff) == 0) {
        iVar1 = queue__600477e4(*(undefined4 *)(param_1 + 0xbc));
      }
      else {
        iVar1 = queue__600c9f94();
      }
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
switchD_60042068_default:
  if (param_4 == 1) {
    local_a8 = 0;
    iVar1 = queue__600473e4(*(undefined4 *)(param_1 + 0xbc),&local_b0,&local_a8);
    bVar3 = iVar1 == 1;
    if (local_a8 != 0) {
      *DAT_60042160 = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
  }
  else {
    if (param_4 != 2) {
      if (param_4 == 0) {
        queue__60047290(*(undefined4 *)(param_1 + 0xbc),&local_b0,0xffffffff,0);
      }
      goto LAB_600420b6;
    }
    iVar1 = queue__60047290(*(undefined4 *)(param_1 + 0xbc),&local_b0,param_5,0);
    bVar3 = iVar1 == 1;
  }
  if (!bVar3) {
    local_a8 = DAT_60042164;
    local_a4 = 0x2de;
    thunk_FUN_600d3b3a(auStack_a0);
    thunk_FUN_600d37ac(auStack_a0,DAT_60042168);
    thunk_FUN_600d415c(auStack_a0,&local_b0);
    thunk_FUN_600d37ac(auStack_a0,DAT_6004216c);
    thunk_FUN_600d415c(auStack_a0,param_1 + 0x560);
    thunk_FUN_601016f0(0x1e,local_a8,local_a4,auStack_a0);
    return 0;
  }
LAB_600420b6:
  *(int *)(param_1 + 100) = local_b0;
  *(uint *)(param_1 + 0x68) = local_ac;
  return 1;
}


