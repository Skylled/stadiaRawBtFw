// 60099204  FUN_60099204  size=202 bytes
// --- callers ---
//   600b8ba4 FUN_600b8ba4
//   600bb534 FUN_600bb534
// --- callees ---
//   60098ec8 FUN_60098ec8
//   6009ff18 FUN_6009ff18
//   60099190 FUN_60099190


void FUN_60099204(undefined4 param_1,undefined1 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = (undefined2 *)FUN_60098ec8(param_1,param_2);
  if (puVar1 != (undefined2 *)0x0) {
    *(undefined1 *)(puVar1 + 0x94) = 0;
    FUN_60099190(2,param_1);
    if ((*(char *)(puVar1 + 0x95) != '\0') &&
       (*(undefined1 *)(puVar1 + 0x95) = 0, *(int *)(DAT_600992d0 + 0x644) != 0)) {
      (**(code **)(DAT_600992d0 + 0x644))(param_1,0,0,0,0,*puVar1,*(undefined1 *)(puVar1 + 0x97));
    }
    iVar2 = FUN_6009ff18(param_1);
    if (iVar2 != 0) {
      if (*(char *)(puVar1 + 0x97) == '\x02') {
        *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) & 0xf9bf;
        if ((*(ushort *)(iVar2 + 0x2a) & 0x1000) == 0) {
          *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) & 0xdfff;
        }
      }
      else {
        *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) & 0xffb8;
      }
    }
  }
  return;
}


