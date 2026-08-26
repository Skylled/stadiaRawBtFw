// 600ffada  FUN_600ffada  size=452 bytes
// --- callers ---
//   600ac524 FUN_600ac524
//   600f43c0 FUN_600f43c0
//   600f70b4 FUN_600f70b4
//   600f6b16 FUN_600f6b16
//   600f46b4 FUN_600f46b4
//   600f395a FUN_600f395a
//   600f3b78 FUN_600f3b78
//   600ac734 FUN_600ac734
// --- callees ---
//   600ffa34 FUN_600ffa34
//   600c7c68 FUN_600c7c68
//   600c7d14 FUN_600c7d14
//   600c7d64 FUN_600c7d64
//   600c7878 FUN_600c7878
//   600c79e4 FUN_600c79e4
//   600c7aac FUN_600c7aac
//   600c78e8 FUN_600c78e8
//   600c7bac FUN_600c7bac


undefined1 FUN_600ffada(int param_1,undefined2 param_2,byte param_3,ushort *param_4)

{
  ushort uVar1;
  ushort local_22;
  int local_20;
  undefined1 local_19;
  
  local_19 = 0x80;
  local_20 = 0;
  local_22 = 0;
  if (param_1 == 0) {
    return 0x80;
  }
  if (param_3 == 0xe) {
    local_20 = FUN_600c7bac(*(undefined2 *)(param_1 + 0x1a),param_4[1],param_4 + 2);
    goto LAB_600ffc7e;
  }
  if (0xe < param_3) {
    if (param_3 == 0x18) {
      local_20 = FUN_600c78e8(0x18,(char)*param_4);
      goto LAB_600ffc7e;
    }
    if (param_3 < 0x19) {
      if (param_3 != 0x12) {
        if (param_3 != 0x16) {
          if (param_3 != 0x10) goto LAB_600ffc7e;
          goto LAB_600ffb7e;
        }
        local_22 = param_4[2];
      }
    }
    else if ((param_3 != 0x52) && (param_3 != 0xd2)) {
      if (param_3 == 0x1e) {
        local_20 = FUN_600c7d14(0x1e);
      }
      goto LAB_600ffc7e;
    }
    if (param_4[1] == 0) {
      local_19 = 0x87;
    }
    else {
      local_20 = FUN_600c7d64(*(undefined2 *)(param_1 + 0x1a),param_3,param_4[1],local_22,param_4[3]
                              ,(undefined1 *)((int)param_4 + 9));
    }
    goto LAB_600ffc7e;
  }
  if (param_3 == 6) {
    local_20 = FUN_600c7aac(*(undefined2 *)(param_1 + 0x1a),param_4);
    goto LAB_600ffc7e;
  }
  if (param_3 < 7) {
    if (param_3 == 2) {
      if (*param_4 < 0x206) {
        *(ushort *)(param_1 + 0x1a) = *param_4;
        local_20 = FUN_600c7878(2,*param_4);
      }
      else {
        local_19 = 0x87;
      }
      goto LAB_600ffc7e;
    }
    if (param_3 != 4) goto LAB_600ffc7e;
LAB_600ffb7e:
    if (((param_4[1] == 0) || (param_4[2] == 0)) || (param_4[2] < param_4[1])) {
      local_19 = 0x87;
    }
    else {
      local_20 = FUN_600c79e4(param_3,param_4[1],param_4[2],*(undefined4 *)(param_4 + 4),
                              *(undefined4 *)(param_4 + 6),*(undefined4 *)(param_4 + 8),
                              *(undefined4 *)(param_4 + 10),*(undefined4 *)(param_4 + 0xc));
    }
  }
  else {
    if (param_3 != 10) {
      if (param_3 != 0xc) {
        if (param_3 != 8) goto LAB_600ffc7e;
        goto LAB_600ffb7e;
      }
      local_22 = param_4[2];
    }
    if (param_3 == 10) {
      uVar1 = *param_4;
    }
    else {
      uVar1 = param_4[1];
    }
    if (uVar1 == 0) {
      local_19 = 0x87;
    }
    else {
      local_20 = FUN_600c7c68(param_3,uVar1,local_22);
    }
  }
LAB_600ffc7e:
  if (local_20 != 0) {
    local_19 = FUN_600ffa34(param_1,param_2,param_3,local_20);
  }
  return local_19;
}


