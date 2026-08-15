// 600655dc  haptics__600655dc  size=178 bytes
// src: haptics.cc
// --- callers ---
//   6006573c haptics__6006573c
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   6010165c FUN_6010165c
//   600653e8 FUN_600653e8


/* src: haptics.cc */

float haptics__600655dc(float param_1,int param_2)

{
  float fVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  uint in_fpscr;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined1 local_18 [4];
  ushort local_14 [2];
  
  fVar1 = DAT_60065690;
  uVar5 = in_fpscr & 0xfffffff | (uint)(param_1 == 0.0) << 0x1e;
  fVar8 = DAT_6006569c;
  if ((byte)(uVar5 >> 0x1e) == 0) {
    fVar8 = ((DAT_60065690 - *(float *)(param_2 + 0x60)) * param_1) / DAT_60065690 +
            *(float *)(param_2 + 0x60);
    puVar3 = (undefined4 *)FUN_600653e8();
    if (*(char *)((int)puVar3 + 0x1a) != '\0') {
      local_18[0] = 4;
      cVar2 = thunk_EXT_FUN_00001ea4(*puVar3,*(undefined1 *)(puVar3 + 1),local_18,1,local_14,2,200);
      if ((cVar2 == '\0') && (local_14[0] != 0)) {
        iVar4 = FUN_600653e8();
        fVar7 = (float)VectorUnsignedToFloat((uint)local_14[0],(byte)(uVar5 >> 0x16) & 3);
        fVar6 = (float)VectorUnsignedToFloat
                                 ((uint)*(ushort *)(*(int *)(iVar4 + 8) + 6),
                                  (byte)(uVar5 >> 0x16) & 3);
        fVar7 = (fVar6 * fVar8) / fVar7;
        if ((int)((uint)(fVar7 < fVar1) << 0x1f) < 0) {
          return fVar7;
        }
        return fVar1;
      }
    }
    FUN_6010165c(0x28,DAT_60065698,0x3b,DAT_60065694);
  }
  return fVar8;
}


