// 600eb75a  FUN_600eb75a  size=116 bytes
// --- callers ---
//   6008dc2c FUN_6008dc2c
//   600eb7ce FUN_600eb7ce
// --- callees ---
//   600e9ba8 FUN_600e9ba8


void FUN_600eb75a(int param_1,int param_2,uint *param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 1 << (param_5 & 0xff);
  uVar3 = uVar6 * 2 - 1;
  uVar4 = *param_3 & uVar3;
  for (uVar5 = 0; uVar5 < param_4 + 1; uVar5 = uVar5 + 1) {
    uVar2 = 0;
    if ((uVar4 & 1) != 0) {
      uVar2 = uVar4;
      if ((uVar4 & uVar6) != 0) {
        if (param_5 + 1 + uVar5 < param_4) {
          uVar2 = uVar4 + uVar6 * -2;
        }
        else {
          uVar2 = (int)uVar3 >> 1 & uVar4;
        }
      }
      uVar4 = uVar4 - uVar2;
    }
    *(char *)(param_2 + uVar5) = (char)uVar2;
    iVar1 = FUN_600e9ba8(param_3,*(undefined4 *)(param_1 + 0xc));
    uVar4 = ((int)uVar4 >> 1) + (iVar1 << (param_5 & 0xff));
  }
  return;
}


