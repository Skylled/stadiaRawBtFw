// 600d9700  FUN_600d9700  size=154 bytes
// --- callers ---
//   60070ad0 switch_pro_controller__60070ad0
//   600712c8 FUN_600712c8
//   60070dcc FUN_60070dcc
// --- callees ---
//   600d96b4 FUN_600d96b4


float FUN_600d9700(float param_1,float *param_2)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  uint uVar6;
  float fVar7;
  float local_24 [2];
  
  if (NAN(*param_2) || NAN(param_1)) {
    uVar1 = in_fpscr & 0xfffffff | (uint)(param_1 < param_2[4]) << 0x1f;
    uVar6 = uVar1 | (uint)(NAN(param_1) || NAN(param_2[4])) << 0x1c;
    if ((byte)(uVar1 >> 0x1f) == ((byte)(uVar6 >> 0x1c) & 1)) {
      fVar2 = param_2[5];
    }
    else {
      iVar5 = 3;
      local_24[0] = param_1;
      while (iVar4 = iVar5, 0 < iVar4) {
        iVar5 = iVar4 >> 1;
        iVar3 = FUN_600d96b4(param_2 + iVar5 * 2,local_24);
        if (iVar3 != 0) {
          param_2 = param_2 + iVar5 * 2 + 2;
          iVar5 = (iVar4 - iVar5) + -1;
        }
      }
      fVar2 = (float)VectorSignedToFloat(param_2[-1],(byte)(uVar6 >> 0x16) & 3);
      fVar7 = (float)VectorSignedToFloat(param_2[1],(byte)(uVar6 >> 0x16) & 3);
      fVar2 = (float)(int)(((fVar7 - fVar2) * (param_1 - param_2[-2])) / (*param_2 - param_2[-2]) +
                          fVar2);
    }
  }
  else {
    fVar2 = param_2[1];
  }
  return fVar2;
}


