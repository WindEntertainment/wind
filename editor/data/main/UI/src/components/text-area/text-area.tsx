import { tw } from "@/tw";
import { TextareaHTMLAttributes, forwardRef } from "react";

import { FormError } from "../form-error";
import { Label } from "../label";

export type TextAreaProps = {
  containerClassName?: string;
  error?: false | string;
  label?: string;
} & TextareaHTMLAttributes<HTMLTextAreaElement>;

export const TextArea = forwardRef<HTMLTextAreaElement, TextAreaProps>(
  ({ className, containerClassName, defaultValue = "", error, label, ...props }, ref) => {
    return (
      <div className={tw("max-w-full", containerClassName)}>
        {!!label && <Label>{label}</Label>}
        <textarea
          className={tw(
            "text-sm flex min-h-[60px] w-full rounded-md border border-stone-200 bg-transparent px-3 py-2 shadow-sm placeholder:text-stone-500 focus-visible:outline-none focus-visible:ring-1 focus-visible:ring-stone-950 disabled:cursor-not-allowed disabled:opacity-50 dark:border-stone-800 dark:placeholder:text-stone-400 dark:focus-visible:ring-stone-300",
            className,
          )}
          defaultValue={defaultValue}
          ref={ref}
          {...props}
        />
        <FormError className="w-full text-end" errorText={error} />
      </div>
    );
  },
);
TextArea.displayName = "Textarea";
