// 60099584  FUN_60099584  size=474 bytes
// --- callers ---
//   600f2262 FUN_600f2262
// --- callees ---
//   600b2764 FUN_600b2764
//   60098f34 FUN_60098f34
//   6009ff18 FUN_6009ff18
//   60099190 FUN_60099190
//   600b218c FUN_600b218c
//   600b2eec FUN_600b2eec


void FUN_60099584(undefined2 param_1,undefined4 param_2,char param_3)

{
  byte bVar1;
  int iVar2;
  undefined2 *puVar3;
  
  bVar1 = FUN_60098f34(param_1);
  if (bVar1 < 4) {
    puVar3 = (undefined2 *)((uint)bVar1 * 0x14c + 0x110 + DAT_60099760);
    if (*(char *)((int)puVar3 + 299) == '\x02') {
      if (param_3 == '\0') {
        *(undefined1 *)((int)puVar3 + 299) = 3;
        *(undefined1 *)((int)puVar3 + 0x12d) = 2;
      }
      else {
        *(undefined1 *)((int)puVar3 + 299) = 0;
        *(undefined1 *)((int)puVar3 + 0x12d) = 0;
      }
      iVar2 = FUN_600b2eec(puVar3 + 3,*(char *)((int)puVar3 + 0x129) == '\0');
      if (iVar2 == 0) {
        *(undefined1 *)((int)puVar3 + 299) = 0;
        *(undefined1 *)((int)puVar3 + 0x12d) = 0;
        FUN_60099190(*(undefined1 *)(DAT_60099760 + 0x7c8),puVar3 + 3);
      }
      else {
        iVar2 = FUN_6009ff18(puVar3 + 3);
        if (iVar2 != 0) {
          *(undefined1 *)(iVar2 + 0xee) = 1;
        }
      }
    }
    else if (*(char *)((int)puVar3 + 299) == '\x04') {
      *(undefined1 *)((int)puVar3 + 299) = 0;
      *(undefined1 *)((int)puVar3 + 0x12d) = 0;
      FUN_60099190(*(undefined1 *)(DAT_60099760 + 0x7c8),puVar3 + 3);
      iVar2 = FUN_6009ff18(puVar3 + 3);
      if (iVar2 != 0) {
        if (*(char *)(iVar2 + 0xee) == '\x02') {
          FUN_600b218c(*(undefined2 *)(iVar2 + 0xc),0x13);
        }
        *(undefined1 *)(iVar2 + 0xee) = 0;
      }
    }
    if (*(char *)(puVar3 + 0x96) == '\x02') {
      if (param_3 == '\0') {
        *(undefined1 *)((int)puVar3 + 0x12d) = 2;
        *(undefined1 *)(puVar3 + 0x96) = 3;
      }
      else {
        *(undefined1 *)(puVar3 + 0x96) = 0;
        *(undefined1 *)((int)puVar3 + 0x12d) = 0;
      }
      iVar2 = FUN_600b2764(*puVar3);
      if (iVar2 == 0) {
        *(undefined1 *)((int)puVar3 + 0x12d) = 0;
        *(undefined1 *)(puVar3 + 0x96) = 0;
        if (*(int *)(DAT_60099760 + 0x7dc) != 0) {
          (**(code **)(DAT_60099760 + 0x7dc))(DAT_60099764);
          *(undefined4 *)(DAT_60099760 + 0x7dc) = 0;
        }
      }
    }
    else if (*(char *)(puVar3 + 0x96) == '\x04') {
      *(undefined1 *)((int)puVar3 + 0x12d) = 0;
      *(undefined1 *)(puVar3 + 0x96) = 0;
      if (*(int *)(DAT_60099760 + 0x7dc) != 0) {
        (**(code **)(DAT_60099760 + 0x7dc))(DAT_60099764);
        *(undefined4 *)(DAT_60099760 + 0x7dc) = 0;
      }
    }
  }
  return;
}


