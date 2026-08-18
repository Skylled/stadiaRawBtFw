// 600cf8de  FUN_600cf8de  size=232 bytes
// --- callers ---
// --- callees ---
//   600cecb6 FUN_600cecb6
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600cec26 FUN_600cec26
//   6013d0b8 thunk_EXT_FUN_000083ec
//   600cf63e FUN_600cf63e


undefined4 FUN_600cf8de(int param_1,undefined4 *param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_30 [24];
  
  thunk_EXT_FUN_0000b5ba(auStack_30,0,0x18);
  iVar3 = *param_3;
  if ((iVar3 == 0) || (iVar5 = param_3[1], iVar5 == 0)) {
    uVar4 = 4;
  }
  else if (param_2[(uint)*(byte *)(param_2 + 0x39) * 2 + 0x2d] == 0) {
    bVar1 = *(byte *)((int)param_2 + 6);
    param_2[2] = 0;
    param_2[*(byte *)(param_2 + 0x39) + 0x35] = iVar5;
    param_2[(uint)*(byte *)(param_2 + 0x39) * 2 + 0x2d] = iVar3;
    param_2[(uint)*(byte *)(param_2 + 0x39) * 2 + 0x2e] = iVar5;
    bVar2 = *(byte *)((int)param_2 + 5);
    *(byte *)(param_2 + 0x39) = *(char *)(param_2 + 0x39) + 1U & 3;
    FUN_600cec26(auStack_30,param_1 + (bVar1 + 0x28) * 4,bVar2,*param_3,bVar2,
                 (int)(short)(ushort)*(byte *)((int)param_2 + 7) * (int)(short)(ushort)bVar2,
                 param_3[1],1);
    *(char *)(param_2 + 1) = *(char *)((int)param_2 + 7) * *(char *)((int)param_2 + 5);
    thunk_EXT_FUN_000083ec(*param_2,auStack_30);
    FUN_600cecb6(*param_2);
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffe3ffff | 1;
    *(uint *)(param_1 + 0x94) =
         (1 << *(sbyte *)((int)param_2 + 6) & 0xfU) << 0x10 | *(uint *)(param_1 + 0x94);
    FUN_600cf63e(param_1,1);
    uVar4 = 0;
  }
  else {
    uVar4 = 0x770;
  }
  return uVar4;
}


