// 600d6460  FUN_600d6460  size=236 bytes
// --- callers ---
//   600d654c FUN_600d654c
// --- callees ---
//   600d643e FUN_600d643e
//   600d5bb6 FUN_600d5bb6
//   600d5d02 FUN_600d5d02
//   600d5bc6 FUN_600d5bc6


undefined4 * FUN_600d6460(undefined4 *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *local_24;
  
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  local_24 = param_2;
  iVar3 = FUN_600d5d02(param_2);
  if (iVar3 != 0) {
    if ((char)param_2[1] == '\0') {
      iVar3 = 1;
      bVar1 = *(byte *)*param_2;
      uVar7 = (uint)((byte *)*param_2)[5];
      for (uVar6 = 0; uVar6 != (bVar1 - 7) / uVar7; uVar6 = uVar6 + 1) {
        switch(uVar7) {
        case 1:
          uVar4 = (uint)*(byte *)(*param_2 + 5 + iVar3);
          break;
        case 2:
          uVar4 = (uint)*(byte *)(*param_2 + 5 + iVar3);
          break;
        case 3:
          uVar4 = FUN_600d5bb6();
          break;
        case 4:
          uVar4 = FUN_600d5bc6();
          break;
        default:
          uVar4 = 0;
        }
        bVar2 = (byte)((uVar4 << 0x1e) >> 0x1f);
        iVar3 = iVar3 + uVar7;
        local_24 = (int *)(CONCAT22(CONCAT11(bVar2,bVar2),CONCAT11((char)uVar4,(char)uVar4)) &
                          0xffff0101);
        FUN_600d643e(param_1,&local_24);
      }
    }
    else if ((char)param_2[1] == ' ') {
      bVar1 = *(byte *)*param_2;
      for (iVar3 = 5; iVar3 != (bVar1 - 6 & 0xfffffffc) + 5; iVar3 = iVar3 + 4) {
        iVar5 = FUN_600d5bc6(*param_2 + iVar3);
        local_24 = (int *)(CONCAT13((byte)((uint)(iVar5 << 0x1c) >> 0x1f),
                                    CONCAT12((byte)((uint)(iVar5 << 0x1d) >> 0x1f),
                                             CONCAT11((byte)((uint)(iVar5 << 0x1e) >> 0x1f),
                                                      (char)iVar5))) & 0xffffff01);
        FUN_600d643e(param_1,&local_24);
      }
    }
  }
  return param_1;
}


