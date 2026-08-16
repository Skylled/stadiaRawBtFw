// 60097488  FUN_60097488  size=256 bytes
// --- callers ---
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600976f8 FUN_600976f8


void FUN_60097488(int param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  char *pcVar7;
  code *pcVar8;
  uint uVar9;
  byte local_a;
  char local_9;
  
  pcVar7 = *(char **)(param_1 + 4);
  local_9 = '\0';
  local_a = 7;
  pcVar8 = *(code **)(DAT_60097588 + 200);
  bVar1 = *(byte *)(DAT_60097588 + 1);
  bVar5 = *(byte *)(DAT_60097588 + 1) >> 4;
  cVar2 = *pcVar7;
  if (*(short *)(param_1 + 2) != 1) {
    bVar3 = pcVar7[1];
    uVar9 = (uint)bVar3;
    if (uVar9 == 1) {
      local_a = 1;
    }
    else if (((uVar9 != 0) && (uVar9 - 5 < 6)) &&
            (local_a = *(byte *)(DAT_6009758c + (bVar3 - 5)), cVar2 == '\0')) {
      cVar4 = pcVar7[2];
      if (bVar3 != 5) {
        local_9 = pcVar7[3];
      }
      iVar6 = thunk_EXT_FUN_0000b554(DAT_60097594,DAT_60097590,6);
      if (iVar6 == 0) {
        FUN_600976f8(cVar4,local_a,0,local_9);
      }
      else {
        FUN_600976f8(cVar4,local_a,DAT_60097598,local_9);
      }
    }
    if ((pcVar8 != (code *)0x0) && (bVar5 == local_a)) {
      *(undefined4 *)(DAT_60097588 + 200) = 0;
      *(undefined1 *)(DAT_60097588 + 1) = 0;
      (*pcVar8)(bVar1 & 0xf,bVar5,cVar2);
    }
  }
  return;
}


