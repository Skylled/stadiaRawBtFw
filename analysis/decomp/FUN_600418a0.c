// 600418a0  FUN_600418a0  size=130 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_600418a0(uint *param_1,uint param_2,uint *param_3,int param_4)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  
  pcVar1 = _DAT_60041924;
  if (param_4 == 0) {
    iVar3 = 0;
  }
  else if ((param_4 == 4) && ((param_2 & 0xffffffc0) == 0)) {
    if (*_DAT_60041924 == '\0') {
      iVar3 = func_0x6004be5c();
      if (iVar3 != 0) {
        return iVar3;
      }
      *pcVar1 = '\x01';
    }
    do {
      puVar2 = _DAT_60041928;
    } while ((int)(*param_1 << 0x17) < 0);
    param_1[2] = 0x200;
    param_1[4] = param_1[4] & 0xffc00fff;
    param_1[4] = (*puVar2 & 0xf) << 0xc | (puVar2[2] & 0x3f) << 0x10 | param_1[4];
    param_1[2] = 0x3f;
    param_1[1] = param_2;
    param_1[0xc] = 1;
    do {
    } while ((int)(*param_1 << 0x17) < 0);
    if ((*param_1 & 0x200) == 0) {
      *param_3 = param_1[0x10];
      iVar3 = 0;
    }
    else {
      iVar3 = 0x4ee8;
    }
  }
  else {
    iVar3 = 4;
  }
  return iVar3;
}


