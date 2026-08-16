// 60099dd0  FUN_60099dd0  size=298 bytes
// --- callers ---
//   600f2a7a FUN_600f2a7a
//   600a96d8 FUN_600a96d8
// --- callees ---
//   600f0406 FUN_600f0406
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ff18 FUN_6009ff18
//   600b218c FUN_600b218c
//   60098ec8 FUN_60098ec8
//   600b26d0 FUN_600b26d0
//   60099190 FUN_60099190


void FUN_60099dd0(char param_1,int param_2,char param_3)

{
  char *pcVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_60099efc;
  if (param_2 != 0) {
    iVar4 = param_2;
  }
  puVar2 = (undefined2 *)FUN_60098ec8(iVar4,1);
  pcVar1 = DAT_60099f00;
  if (puVar2 == (undefined2 *)0x0) {
    if (param_1 == '\0') {
      return;
    }
    FUN_60099190(param_1,param_2);
    return;
  }
  *DAT_60099f00 = param_1;
  if (param_1 == '\0') {
    pcVar1[1] = param_3;
    thunk_EXT_FUN_0000b572(pcVar1 + 2,iVar4,6);
    *(char *)((int)puVar2 + 0x129) = param_3;
    if (param_3 == '\0') {
      FUN_600f0406(puVar2 + 3,puVar2[0x86]);
    }
  }
  if (*(char *)((int)puVar2 + 299) == '\x03') {
    if (*(char *)(puVar2 + 0x96) == '\x03') {
      *(undefined1 *)((int)puVar2 + 299) = 4;
      return;
    }
    iVar3 = FUN_600b26d0(*puVar2,1);
    if (iVar3 != 0) {
      *(undefined1 *)((int)puVar2 + 0x12d) = 3;
      *(undefined1 *)((int)puVar2 + 299) = 4;
      return;
    }
  }
  if (*(char *)((int)puVar2 + 299) == '\x05') {
    *(undefined1 *)((int)puVar2 + 299) = 0;
    *(undefined1 *)((int)puVar2 + 0x12d) = 0;
  }
  FUN_60099190(param_1,param_2);
  iVar4 = FUN_6009ff18(iVar4);
  if (iVar4 != 0) {
    if (*(char *)(iVar4 + 0xee) == '\x02') {
      FUN_600b218c(*(undefined2 *)(iVar4 + 0xc),0x13);
    }
    *(undefined1 *)(iVar4 + 0xee) = 0;
  }
  return;
}


