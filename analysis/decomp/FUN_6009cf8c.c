// 6009cf8c  FUN_6009cf8c  size=2464 bytes
// --- callers ---
//   6009ce30 FUN_6009ce30
//   6009cec8 FUN_6009cec8
// --- callees ---
//   6004cb28 FUN_6004cb28


char * FUN_6009cf8c(uint *param_1,undefined4 *param_2,undefined2 *param_3)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  byte local_21;
  ushort local_20;
  ushort local_1e;
  char *local_1c;
  char *local_18;
  uint local_14;
  
  local_14 = *param_1;
  local_18 = (char *)*param_2;
  local_1c = (char *)0x0;
  local_1e = 0x1f;
  local_20 = 0;
  if (local_14 != 0) {
    if ((local_14 & 2) != 0) {
      *local_18 = '\x02';
      local_1c = local_18 + 2;
      local_18[1] = '\x01';
      if (param_3 == (undefined2 *)0x0) {
        *local_1c = '\0';
      }
      else {
        *local_1c = *(char *)(param_3 + 0x15);
      }
      local_18 = local_18 + 3;
      local_1e = 0x1c;
      local_14 = local_14 & 0xfffffffd;
    }
    if ((3 < local_1e) && ((local_14 & 0x800) != 0)) {
      *local_18 = '\x03';
      local_18[1] = '\x19';
      pcVar2 = local_18 + 3;
      local_18[2] = (char)param_3[0x14];
      local_18 = local_18 + 4;
      *pcVar2 = (char)((ushort)param_3[0x14] >> 8);
      local_1e = local_1e - 4;
      local_14 = local_14 & 0xfffff7ff;
    }
    if ((2 < local_1e) && ((local_14 & 1) != 0)) {
      uVar1 = FUN_6004cb28(DAT_6009d2c4);
      if ((local_1e - 2 & 0xffff) < uVar1) {
        *local_18 = (char)local_1e + -1;
        local_18[1] = '\b';
        local_18 = local_18 + 2;
        for (iVar3 = 0; iVar3 < (int)(local_1e - 2); iVar3 = iVar3 + 1) {
          *local_18 = *(char *)(DAT_6009d2c4 + iVar3);
          local_18 = local_18 + 1;
        }
      }
      else {
        local_20 = FUN_6004cb28(DAT_6009d2c4);
        *local_18 = (char)local_20 + '\x01';
        local_18[1] = '\t';
        local_18 = local_18 + 2;
        for (iVar3 = 0; iVar3 < (int)(uint)local_20; iVar3 = iVar3 + 1) {
          *local_18 = *(char *)(DAT_6009d2c4 + iVar3);
          local_18 = local_18 + 1;
        }
      }
      local_1e = (local_1e - local_20) - 2;
      local_14 = local_14 & 0xfffffffe;
    }
    if (((((2 < local_1e) && ((local_14 & 4) != 0)) && (param_3 != (undefined2 *)0x0)) &&
        ((*(int *)(param_3 + 2) != 0 && (**(char **)(param_3 + 2) != '\0')))) &&
       (*(int *)(*(int *)(param_3 + 2) + 4) != 0)) {
      if ((int)(local_1e - 2) < (int)(uint)**(byte **)(param_3 + 2)) {
        local_20 = local_1e - 2;
      }
      else {
        local_20 = (ushort)**(byte **)(param_3 + 2);
      }
      *local_18 = (char)local_20 + '\x01';
      local_18[1] = -1;
      local_18 = local_18 + 2;
      for (iVar3 = 0; iVar3 < (int)(uint)local_20; iVar3 = iVar3 + 1) {
        *local_18 = *(char *)(iVar3 + *(int *)(*(int *)(param_3 + 2) + 4));
        local_18 = local_18 + 1;
      }
      local_1e = (local_1e - local_20) - 2;
      local_14 = local_14 & 0xfffffffb;
    }
    if (((2 < local_1e) && ((local_14 & 8) != 0)) && (param_3 != (undefined2 *)0x0)) {
      *local_18 = '\x02';
      pcVar2 = local_18 + 2;
      local_18[1] = '\n';
      local_18 = local_18 + 3;
      *pcVar2 = *(char *)((int)param_3 + 0x2b);
      local_1e = local_1e - 3;
      local_14 = local_14 & 0xfffffff7;
    }
    if (((((2 < local_1e) && ((local_14 & 0x40) != 0)) && (param_3 != (undefined2 *)0x0)) &&
        ((*(int *)(param_3 + 4) != 0 && (**(char **)(param_3 + 4) != '\0')))) &&
       (*(int *)(*(int *)(param_3 + 4) + 4) != 0)) {
      if ((uint)**(byte **)(param_3 + 4) * 2 - (local_1e - 2) == 0 ||
          (int)((uint)**(byte **)(param_3 + 4) * 2) < (int)(local_1e - 2)) {
        if (*(char *)(*(int *)(param_3 + 4) + 1) == '\0') {
          local_20 = (ushort)**(byte **)(param_3 + 4);
          *local_18 = **(byte **)(param_3 + 4) * '\x02' + '\x01';
          local_18[1] = '\x02';
        }
        else {
          local_20 = (ushort)**(byte **)(param_3 + 4);
          *local_18 = **(byte **)(param_3 + 4) * '\x02' + '\x01';
          local_18[1] = '\x03';
        }
      }
      else {
        iVar3 = local_1e - 2;
        if (iVar3 < 0) {
          iVar3 = local_1e - 1;
        }
        local_20 = (ushort)(iVar3 >> 1);
        *local_18 = (char)(iVar3 >> 1) * '\x02' + '\x01';
        local_18[1] = '\x02';
      }
      pcVar2 = local_18;
      for (local_21 = 0; local_18 = pcVar2 + 2, local_21 < local_20; local_21 = local_21 + 1) {
        *local_18 = (char)*(undefined2 *)((uint)local_21 * 2 + *(int *)(*(int *)(param_3 + 4) + 4));
        pcVar2[3] = (char)((ushort)*(undefined2 *)
                                    ((uint)local_21 * 2 + *(int *)(*(int *)(param_3 + 4) + 4)) >> 8)
        ;
        pcVar2 = local_18;
      }
      local_1e = local_1e + (local_20 + 1 & 0x7fff) * -2;
      local_14 = local_14 & 0xffffffbf;
    }
    if (((2 < local_1e) && ((local_14 & 0x10) != 0)) &&
       ((param_3 != (undefined2 *)0x0 &&
        (((*(int *)(param_3 + 8) != 0 && (**(char **)(param_3 + 8) != '\0')) &&
         (*(int *)(*(int *)(param_3 + 8) + 4) != 0)))))) {
      if ((uint)**(byte **)(param_3 + 8) * 4 - (local_1e - 2) == 0 ||
          (int)((uint)**(byte **)(param_3 + 8) * 4) < (int)(local_1e - 2)) {
        if (*(char *)(*(int *)(param_3 + 4) + 1) == '\0') {
          local_20 = (ushort)**(byte **)(param_3 + 8);
          *local_18 = **(byte **)(param_3 + 8) * '\x04' + '\x01';
          local_18[1] = '\x04';
        }
        else {
          local_20 = (ushort)**(byte **)(param_3 + 8);
          *local_18 = **(byte **)(param_3 + 8) * '\x04' + '\x01';
          local_18[1] = '\x05';
        }
      }
      else {
        iVar3 = local_1e - 2;
        if (iVar3 < 0) {
          iVar3 = local_1e + 1;
        }
        local_20 = (ushort)(iVar3 >> 2);
        *local_18 = (char)(iVar3 >> 2) * '\x04' + '\x01';
        local_18[1] = '\x04';
      }
      local_18 = local_18 + 2;
      for (local_21 = 0; local_21 < local_20; local_21 = local_21 + 1) {
        *local_18 = (char)*(undefined4 *)((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 8) + 4));
        local_18[1] = (char)((uint)*(undefined4 *)
                                    ((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 8) + 4)) >> 8)
        ;
        pcVar2 = local_18 + 3;
        local_18[2] = (char)((uint)*(undefined4 *)
                                    ((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 8) + 4)) >>
                            0x10);
        local_18 = local_18 + 4;
        *pcVar2 = (char)((uint)*(undefined4 *)
                                ((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 8) + 4)) >> 0x18);
      }
      local_1e = (local_1e + local_20 * -4) - 2;
      local_14 = local_14 & 0xffffffef;
    }
    if (((0x11 < local_1e) && ((local_14 & 0x10000) != 0)) &&
       ((param_3 != (undefined2 *)0x0 && (*(int *)(param_3 + 6) != 0)))) {
      *local_18 = '\x11';
      if (**(char **)(param_3 + 6) == '\0') {
        local_18[1] = '\x06';
      }
      else {
        local_18[1] = '\a';
      }
      local_18 = local_18 + 2;
      for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
        *local_18 = *(char *)(*(int *)(param_3 + 6) + iVar3 + 1);
        local_18 = local_18 + 1;
      }
      local_1e = local_1e - 0x12;
      local_14 = local_14 & 0xfffeffff;
    }
    pcVar2 = local_18;
    if (((2 < local_1e) && ((local_14 & 0x4000) != 0)) &&
       ((param_3 != (undefined2 *)0x0 &&
        (((*(int *)(param_3 + 0xc) != 0 && (**(char **)(param_3 + 0xc) != '\0')) &&
         (*(int *)(*(int *)(param_3 + 0xc) + 4) != 0)))))) {
      if ((uint)**(byte **)(param_3 + 0xc) * 4 - (local_1e - 2) == 0 ||
          (int)((uint)**(byte **)(param_3 + 0xc) * 4) < (int)(local_1e - 2)) {
        local_20 = (ushort)**(byte **)(param_3 + 0xc);
        *local_18 = **(byte **)(param_3 + 0xc) * '\x04' + '\x01';
      }
      else {
        iVar3 = local_1e - 2;
        if (iVar3 < 0) {
          iVar3 = local_1e + 1;
        }
        local_20 = (ushort)(iVar3 >> 2);
        *local_18 = (char)(iVar3 >> 2) * '\x04' + '\x01';
      }
      local_18 = local_18 + 1;
      *local_18 = '\x1b';
      local_18 = pcVar2 + 2;
      for (local_21 = 0; local_21 < local_20; local_21 = local_21 + 1) {
        *local_18 = (char)*(undefined4 *)
                           ((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 0xc) + 4));
        local_18[1] = (char)((uint)*(undefined4 *)
                                    ((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 0xc) + 4)) >>
                            8);
        pcVar2 = local_18 + 3;
        local_18[2] = (char)((uint)*(undefined4 *)
                                    ((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 0xc) + 4)) >>
                            0x10);
        local_18 = local_18 + 4;
        *pcVar2 = (char)((uint)*(undefined4 *)
                                ((uint)local_21 * 4 + *(int *)(*(int *)(param_3 + 0xc) + 4)) >> 0x18
                        );
      }
      local_1e = (local_1e + local_20 * -4) - 2;
      local_14 = local_14 & 0xffffbfff;
    }
    if (((0x11 < local_1e) && ((local_14 & 0x400) != 0)) &&
       ((param_3 != (undefined2 *)0x0 && (*(int *)(param_3 + 0xe) != 0)))) {
      *local_18 = '\x11';
      local_18[1] = '\x15';
      local_18 = local_18 + 2;
      for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
        *local_18 = *(char *)(*(int *)(param_3 + 0xe) + iVar3 + 1);
        local_18 = local_18 + 1;
      }
      local_1e = local_1e - 0x12;
      local_14 = local_14 & 0xfffffbff;
    }
    if (((2 < local_1e) && ((local_14 & 0x100) != 0)) &&
       ((param_3 != (undefined2 *)0x0 &&
        (((*(char *)(*(int *)(param_3 + 0x12) + 0x14) != '\0' &&
          (*(int *)(*(int *)(param_3 + 0x12) + 0x18) != 0)) &&
         (**(ushort **)(param_3 + 0x12) + 2 < (uint)local_1e)))))) {
      if ((int)(local_1e - 2) < (int)(uint)*(byte *)(*(int *)(param_3 + 0x12) + 0x14)) {
        local_20 = (local_1e - **(short **)(param_3 + 0x12)) - 2;
      }
      else {
        local_20 = (ushort)*(byte *)(*(int *)(param_3 + 0x12) + 0x14);
      }
      pcVar2 = local_18 + 1;
      *local_18 = (char)**(undefined2 **)(param_3 + 0x12) + (char)local_20 + '\x01';
      if (**(short **)(param_3 + 0x12) == 2) {
        *pcVar2 = '\x16';
        pcVar2 = local_18 + 3;
        local_18[2] = (char)*(undefined2 *)(*(int *)(param_3 + 0x12) + 4);
        local_18 = local_18 + 4;
        *pcVar2 = (char)((ushort)*(undefined2 *)(*(int *)(param_3 + 0x12) + 4) >> 8);
      }
      else if (**(short **)(param_3 + 0x12) == 4) {
        *pcVar2 = '\x1c';
        local_18[2] = (char)*(undefined4 *)(*(int *)(param_3 + 0x12) + 4);
        local_18[3] = (char)((uint)*(undefined4 *)(*(int *)(param_3 + 0x12) + 4) >> 8);
        pcVar2 = local_18 + 5;
        local_18[4] = (char)((uint)*(undefined4 *)(*(int *)(param_3 + 0x12) + 4) >> 0x10);
        local_18 = local_18 + 6;
        *pcVar2 = (char)((uint)*(undefined4 *)(*(int *)(param_3 + 0x12) + 4) >> 0x18);
      }
      else {
        *pcVar2 = '\x1d';
        local_18 = local_18 + 2;
        for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
          *local_18 = *(char *)(*(int *)(param_3 + 0x12) + iVar3 + 4);
          local_18 = local_18 + 1;
        }
      }
      for (iVar3 = 0; iVar3 < (int)(uint)local_20; iVar3 = iVar3 + 1) {
        *local_18 = *(char *)(iVar3 + *(int *)(*(int *)(param_3 + 0x12) + 0x18));
        local_18 = local_18 + 1;
      }
      local_1e = (local_1e - (local_20 + **(short **)(param_3 + 0x12))) - 2;
      local_14 = local_14 & 0xfffffeff;
    }
    if (((5 < local_1e) && ((local_14 & 0x20) != 0)) && (param_3 != (undefined2 *)0x0)) {
      *local_18 = '\x05';
      local_18[1] = '\x12';
      local_18[2] = (char)*param_3;
      local_18[3] = (char)((ushort)*param_3 >> 8);
      pcVar2 = local_18 + 5;
      local_18[4] = (char)param_3[1];
      local_18 = local_18 + 6;
      *pcVar2 = (char)((ushort)param_3[1] >> 8);
      local_1e = local_1e - 6;
      local_14 = local_14 & 0xffffffdf;
    }
    if ((((local_14 & 0x8000) != 0) && (param_3 != (undefined2 *)0x0)) &&
       (*(int *)(param_3 + 0x10) != 0)) {
      local_21 = 0;
      for (; (local_21 < **(byte **)(param_3 + 0x10) &&
             (pcVar2 = (char *)((uint)local_21 * 8 + *(int *)(*(int *)(param_3 + 0x10) + 4)),
             (ushort)((byte)pcVar2[1] + 2) <= local_1e));
          local_1e = (local_1e - (byte)pcVar2[1]) - 2) {
        *local_18 = pcVar2[1] + '\x01';
        local_18[1] = *pcVar2;
        local_18 = local_18 + 2;
        for (iVar3 = 0; iVar3 < (int)(uint)(byte)pcVar2[1]; iVar3 = iVar3 + 1) {
          *local_18 = *(char *)(iVar3 + *(int *)(pcVar2 + 4));
          local_18 = local_18 + 1;
        }
        local_21 = local_21 + 1;
      }
      local_14 = local_14 & 0xffff7fff;
    }
  }
  *param_1 = local_14;
  *param_2 = local_18;
  return local_1c;
}


