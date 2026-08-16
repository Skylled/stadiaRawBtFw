// 600bcca8  FUN_600bcca8  size=434 bytes
// --- callers ---
//   600b9408 FUN_600b9408
// --- callees ---
//   600d9250 FUN_600d9250
//   600fa1dc FUN_600fa1dc
//   6006e0bc FUN_6006e0bc
//   600bcf88 FUN_600bcf88
//   600b85e4 FUN_600b85e4
//   600f82ea FUN_600f82ea
//   600bce60 FUN_600bce60


int FUN_600bcca8(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  int local_10;
  int local_c;
  
  local_10 = 0;
  do {
    if (3 < local_10) {
      puVar3 = (undefined2 *)FUN_600fa1dc(param_1);
      if (puVar3 == (undefined2 *)0x0) {
        local_c = 0;
      }
      else {
        if (*(char *)(puVar3 + 0x3f) == '\0') {
          local_c = FUN_600d9250(puVar3 + 0x98);
          if (local_c == 0) {
            return 0;
          }
        }
        else {
          local_c = FUN_600b85e4(puVar3,0);
          if (local_c == 0) {
            return 0;
          }
        }
        if (((*(int *)(puVar3 + 0xaa) != 0) && (*(int *)(*(int *)(puVar3 + 0xaa) + 0x30) != 0)) &&
           (*(char *)(puVar3 + 0x3f) != '\x03')) {
          (**(code **)(*(int *)(puVar3 + 0xaa) + 0x30))(*puVar3,1);
        }
        FUN_600bcf88(puVar3);
        FUN_600bce60(local_c,puVar3);
      }
      return local_c;
    }
    puVar3 = *(undefined2 **)(param_1 + (local_10 + 0x24) * 4);
    if (puVar3 != (undefined2 *)0x0) {
      if (*(char *)(puVar3 + 0x3f) == '\0') {
        if ((puVar3[0x9c] != 0) && (iVar2 = FUN_600d9250(puVar3 + 0x98), iVar2 != 0)) {
          if (*(int *)(local_10 * 0x1c + DAT_600bce5c + 0xee8) != 0) {
            (**(code **)(local_10 * 0x1c + DAT_600bce5c + 0xee8))(*puVar3,1);
          }
          FUN_600bcf88(puVar3);
          FUN_600bce60(iVar2,puVar3);
          return iVar2;
        }
      }
      else if ((((*(char *)(puVar3 + 0x5d) == '\0') && (*(char *)(puVar3 + 0x5b) == '\0')) &&
               ((puVar3[0x72] != 0 ||
                (((puVar3[0x9c] != 0 &&
                  ((*(char *)(puVar3 + 0x56) != '\x02' || (uVar1 = FUN_6006e0bc(2), uVar1 < 0x5b))))
                 && ((*(char *)(puVar3 + 0x3f) != '\x03' ||
                     (iVar2 = FUN_600f82ea(puVar3), iVar2 == 0)))))))) &&
              (iVar2 = FUN_600b85e4(puVar3,0), iVar2 != 0)) {
        FUN_600bce60(iVar2,puVar3);
        return iVar2;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}


