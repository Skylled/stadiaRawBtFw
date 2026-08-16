// 60069dd4  FUN_60069dd4  size=960 bytes
// --- callers ---
// --- callees ---
//   600691f4 adapter__600691f4
//   600695dc adapter__600695dc
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d37b8 FUN_600d37b8
//   601016f0 FUN_601016f0
//   600d88b4 FUN_600d88b4
//   60069c58 adapter__60069c58
//   600f7b48 FUN_600f7b48
//   600691cc adapter__600691cc
//   60069130 FUN_60069130
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d37ac FUN_600d37ac
//   600cc8f8 FUN_600cc8f8
//   600d3618 FUN_600d3618
//   600cc984 FUN_600cc984
//   60093358 FUN_60093358
//   60069570 adapter__60069570
//   60069964 adapter__60069964
//   60069d50 adapter__60069d50
//   6006988c adapter__6006988c
//   600d3b3a FUN_600d3b3a
//   60069a38 adapter__60069a38
//   600cdcc4 FUN_600cdcc4
//   60069160 adapter__60069160
//   600d7d4c thunk_FUN_600d7cdc
//   60069648 adapter__60069648
//   60069b20 adapter__60069b20
//   6010165c FUN_6010165c


void FUN_60069dd4(undefined4 param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  byte bVar2;
  uint *puVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  undefined2 *puVar8;
  uint uVar9;
  int unaff_r4;
  bool bVar10;
  undefined1 *in_stack_0000000c;
  undefined1 uStack00000024;
  undefined1 uStack00000026;
  undefined1 uStack00000027;
  undefined1 uStack00000028;
  undefined1 uStack00000029;
  undefined1 uStack0000002a;
  undefined1 uStack0000002b;
  undefined1 in_stack_00000038;
  undefined4 *in_stack_0000003c;
  uint in_stack_00000040;
  
  pbVar4 = DAT_6006a0d0;
  puVar3 = DAT_6006a0a8;
  switch(param_1) {
  case 0:
    if (param_2[1] != '\0') {
      in_stack_0000003c = (undefined4 *)DAT_6006a098;
      in_stack_00000040 = 0x403;
      FUN_600d3b3a(&stack0x00000044);
      FUN_600d37ac(&stack0x00000044,DAT_6006a09c);
      FUN_600d88b4(&stack0x00000044,*(undefined1 *)(unaff_r4 + 1));
LAB_60069e3a:
      FUN_600d37b8(&stack0x0000003c);
      goto LAB_60069e0a;
    }
    adapter__6006988c(DAT_6006a094,*param_2);
    break;
  case 1:
    adapter__60069a38(DAT_6006a094,*(undefined2 *)(param_2 + 0xc),*(undefined4 *)(unaff_r4 + 8),
                      **(undefined2 **)(param_2 + 0x10));
    break;
  case 2:
    if (*(char *)(*(int *)(param_2 + 0x10) + 0x25f) == '\0') {
      *(undefined4 *)(DAT_6006a0a0 + 0x31f4) = 0;
    }
    puVar8 = *(undefined2 **)(unaff_r4 + 0x10);
    in_stack_00000040 = (uint)(ushort)puVar8[2];
    in_stack_0000003c = (undefined4 *)(puVar8 + 3);
    adapter__60069160(DAT_6006a094,*puVar8,puVar8[1]);
    puVar8 = *(undefined2 **)(unaff_r4 + 0x10);
    if (*(char *)((int)puVar8 + 0x25f) != '\0') {
      thunk_EXT_FUN_0000b5ba(&stack0x0000003c,0,0x262);
      uVar1 = *(undefined2 *)(unaff_r4 + 0xc);
      in_stack_0000003c = (undefined4 *)CONCAT22(*puVar8,uVar1);
      in_stack_00000040 = *(uint *)(puVar8 + 1);
      thunk_EXT_FUN_0000b572(&stack0x00000045,puVar8 + 3,puVar8[2]);
      uVar6 = *(undefined4 *)(unaff_r4 + 8);
      goto FUN_60069ed4;
    }
    adapter__60069b20(DAT_6006a094);
    if (*(char *)(*(int *)(unaff_r4 + 0x10) + 0x25e) != '\0') goto LAB_60069ef6;
    break;
  case 3:
    if (**(char **)(param_2 + 0x10) == '\0') {
      adapter__600691cc();
    }
    else {
      adapter__60069b20(DAT_6006a094);
    }
LAB_60069ef6:
    uVar6 = *(undefined4 *)(unaff_r4 + 8);
    uVar1 = *(undefined2 *)(unaff_r4 + 0xc);
FUN_60069ed4:
    FUN_60095904(uVar1,uVar6);
    break;
  case 4:
    FUN_6010165c(0x14,DAT_6006a098,0x445,DAT_6006a0a4);
    break;
  case 5:
    if (param_2[2] != '\0') {
      bVar2 = *DAT_6006a0d0;
      DataMemoryBarrier(0x1b);
      if (((bVar2 & 1) == 0) && (iVar5 = FUN_600cc8f8(DAT_6006a0d0), iVar5 != 0)) {
        *puVar3 = bVar2 & 1;
        FUN_600cc984(pbVar4);
      }
      uVar9 = FUN_600d3618();
      puVar8 = DAT_6006a098;
      if (uVar9 < *puVar3 + 5000) goto LAB_60069e0a;
      *puVar3 = uVar9;
      in_stack_0000003c = (undefined4 *)puVar8;
      in_stack_00000040 = 0x44a;
      FUN_600d3b3a(&stack0x00000044);
      FUN_600d37ac(&stack0x00000044,DAT_6006a0ac);
      FUN_600d88b4(&stack0x00000044,*(undefined1 *)(unaff_r4 + 2));
      FUN_600d37ac(&stack0x00000044,DAT_6006a0b0);
      uVar9 = (uint)*(byte *)(unaff_r4 + 2);
LAB_60069f92:
      uVar6 = DAT_6006a0b8;
      if (uVar9 < 0x93) {
        uVar6 = *(undefined4 *)(DAT_6006a0b4 + uVar9 * 4);
      }
      FUN_600d37ac(&stack0x00000044,uVar6);
      FUN_600d37ac(&stack0x00000044,DAT_6006a0bc);
      goto LAB_60069e3a;
    }
    break;
  case 6:
    if (param_2[1] != '\0') {
      FUN_6010165c(0x28,DAT_6006a098,0x454,DAT_6006a0c0);
      goto LAB_60069e0a;
    }
    break;
  case 7:
    if (param_2[8] != '\0') {
      in_stack_0000003c = (undefined4 *)DAT_6006a098;
      in_stack_00000040 = 0x45d;
      FUN_600d3b3a(&stack0x00000044);
      FUN_600d37ac(&stack0x00000044,DAT_6006a0c4);
      FUN_600d88b4(&stack0x00000044,*(undefined1 *)(unaff_r4 + 8));
      FUN_600d37ac(&stack0x00000044,DAT_6006a0b0);
      uVar9 = (uint)*(byte *)(unaff_r4 + 8);
      goto LAB_60069f92;
    }
    adapter__60069570(&stack0x0000003c,*(undefined4 *)(param_2 + 4));
    adapter__60069964(DAT_6006a094,&stack0x0000003c,*(undefined2 *)(unaff_r4 + 2));
    break;
  case 9:
    if (param_2[0xc] != '\0') {
      in_stack_0000003c = (undefined4 *)DAT_6006a098;
      in_stack_00000040 = 0x46a;
      FUN_600d3b3a(&stack0x00000044);
      uVar6 = DAT_6006a0c8;
LAB_6006a04a:
      FUN_600d37ac(&stack0x00000044,uVar6);
      FUN_600d88b4(&stack0x00000044,*(undefined1 *)(unaff_r4 + 0xc));
      FUN_600d37ac(&stack0x00000044,DAT_6006a0b0);
      uVar9 = (uint)*(byte *)(unaff_r4 + 0xc);
      goto LAB_60069f92;
    }
    adapter__60069570(&stack0x0000003c,*(undefined4 *)(param_2 + 8));
    adapter__600695dc(DAT_6006a094,&stack0x0000003c,*(undefined2 *)(unaff_r4 + 2),
                      *(undefined2 *)(unaff_r4 + 4));
    break;
  case 10:
    if (param_2[0xc] != '\0') {
      in_stack_0000003c = (undefined4 *)DAT_6006a098;
      in_stack_00000040 = 0x477;
      FUN_600d3b3a(&stack0x00000044);
      uVar6 = DAT_6006a0cc;
      goto LAB_6006a04a;
    }
    adapter__60069570(&stack0x0000003c,*(undefined4 *)(param_2 + 8));
    adapter__60069648(DAT_6006a094,&stack0x0000003c,*(undefined2 *)(unaff_r4 + 2),
                      *(undefined2 *)(unaff_r4 + 4));
    break;
  case 0xe:
    uStack00000028 = *(undefined1 *)(unaff_r4 + 4);
    uStack00000029 = *(undefined1 *)(unaff_r4 + 3);
    uStack0000002a = *(undefined1 *)(unaff_r4 + 2);
    uStack0000002b = *(undefined1 *)(unaff_r4 + 1);
    uStack00000027 = *(undefined1 *)(unaff_r4 + 5);
    uStack00000026 = *(undefined1 *)(unaff_r4 + 6);
    in_stack_00000038 = 0;
    uStack00000024 = 0;
    thunk_EXT_FUN_0000b5ba(&stack0x00000010,0,0x12);
    FUN_60069130((int)&stack0x00000024 + 2,&stack0x00000010,0x12);
    in_stack_0000003c = &stack0x0000000c;
    in_stack_0000000c = &stack0x00000010;
    iVar5 = thunk_FUN_600d7cdc();
    if (iVar5 != 0) {
      FUN_600cdcc4(&stack0x00000040,0x28,DAT_6006a1fc,*in_stack_0000003c);
    }
    puVar8 = DAT_6006a200;
    FUN_6010165c(0x14,DAT_6006a200,0x48c,DAT_6006a204);
    adapter__60069c58(DAT_6006a208,*(undefined2 *)(unaff_r4 + 8),&stack0x00000024);
    uVar6 = FUN_600f7b48(unaff_r4 + 1,6,8,0);
    in_stack_00000040 = 0x49a;
    in_stack_0000003c = (undefined4 *)puVar8;
    FUN_600d3b3a(&stack0x00000044);
    FUN_600d37ac(&stack0x00000044,DAT_6006a20c);
    FUN_600d88b4(&stack0x00000044,uVar6);
    FUN_601016f0(0x14,in_stack_0000003c,in_stack_00000040,&stack0x00000044);
    FUN_60093358(unaff_r4 + 1,2,DAT_6006a210);
    break;
  case 0xf:
    FUN_6010165c(0x14,DAT_6006a200,0x4a7,DAT_6006a218);
    uVar7 = *(ushort *)(unaff_r4 + 10);
    if (uVar7 != 0x16) {
      if (uVar7 < 0x17) {
        if (uVar7 != 1) {
          if (uVar7 == 0) {
            uVar7 = 0x1f;
          }
          else if (uVar7 != 8) {
            bVar10 = uVar7 == 0x13;
            goto LAB_6006a1cc;
          }
        }
      }
      else if (uVar7 != 0x3e) {
        if (uVar7 < 0x3f) {
          bVar10 = uVar7 == 0x22;
LAB_6006a1cc:
          if (!bVar10) {
LAB_6006a1ce:
            uVar7 = 0x11;
          }
        }
        else if (uVar7 == 0x100) {
          uVar7 = 0xc;
        }
        else {
          if (uVar7 != 0x101) goto LAB_6006a1ce;
          uVar7 = 0xd;
        }
      }
    }
    adapter__60069d50(DAT_6006a208,*(undefined2 *)(unaff_r4 + 8),uVar7);
  }
LAB_60069e0a:
  adapter__600691f4(DAT_6006a094);
  return;
}


