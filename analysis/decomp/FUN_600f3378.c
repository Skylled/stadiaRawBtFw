// 600f3378  FUN_600f3378  size=308 bytes
// --- callers ---
// --- callees ---
//   600f0726 FUN_600f0726
//   6004cb28 FUN_6004cb28
//   600aa744 FUN_600aa744
//   600f32aa FUN_600f32aa


void FUN_600f3378(undefined2 param_1,char param_2,char param_3,int param_4)

{
  short sVar1;
  int iVar2;
  byte *pbVar3;
  ushort local_12;
  
  iVar2 = FUN_600aa744(param_1);
  if ((iVar2 != 0) && (sVar1 = *(short *)(iVar2 + 0xe), param_2 == '\x02')) {
    if (param_3 == '\0') {
      pbVar3 = (byte *)(param_4 + 9);
      if (sVar1 == 0x2a04) {
        FUN_600f0726(iVar2,(ushort)*(byte *)(param_4 + 10) * 0x100 + (ushort)*pbVar3,
                     (ushort)*(byte *)(param_4 + 0xc) * 0x100 + (ushort)*(byte *)(param_4 + 0xb),
                     (ushort)*(byte *)(param_4 + 0xe) * 0x100 + (ushort)*(byte *)(param_4 + 0xd),
                     (ushort)*(byte *)(param_4 + 0x10) * 0x100 + (ushort)*(byte *)(param_4 + 0xf));
        FUN_600f32aa(iVar2,1,0,0);
      }
      else if (sVar1 == 0x2aa6) {
        FUN_600f32aa(iVar2,1,1,pbVar3);
      }
      else if (sVar1 == 0x2a00) {
        local_12 = FUN_6004cb28(pbVar3);
        if (0xf8 < local_12) {
          local_12 = 0xf8;
        }
        FUN_600f32aa(iVar2,1,local_12,pbVar3);
      }
    }
    else {
      FUN_600f32aa(iVar2,0,0,0);
    }
  }
  return;
}


